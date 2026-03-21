# HomeAssistantVoiceSatallite-ESP32-S3

ESPHome firmware project for an `ESP32-S3-BOX-3` acting as a lean Home
Assistant Assist voice satellite.

## What Is In This Repo

- firmware YAML: `src/esphome/esp32-s3-box-3-voice.yaml`
- local secrets template: `src/esphome/secrets.example.yaml`
- display asset folder: `src/esphome/assets/`
- setup notes: `docs/esphome-setup.md`
- future hardware-testing handoff prompt: `TESTING_SESSION_README.md`

## Requirements

- ESPHome installed locally or available through a standard ESPHome install
- an `ESP32-S3-BOX-3`
- USB connection for the first flash
- Home Assistant reachable on your network

## Prepare The Config

1. Copy `src/esphome/secrets.example.yaml` to `src/esphome/secrets.yaml`.
2. Replace the placeholder Wi-Fi, API, and OTA values in `src/esphome/secrets.yaml`.
3. Select the active face in `src/esphome/face-theme-params.yaml`.
4. Confirm the matching asset exists in `src/esphome/assets/`.

## Secrets File Values

These values are stored in:

- `src/esphome/secrets.yaml`

They are initially shown in:

- `src/esphome/secrets.example.yaml`

The expected keys are:

```yaml
wifi_ssid: "Private"
wifi_password: "REPLACE_ME_WIFI_PASSWORD"
api_encryption_key: "REPLACE_ME_BASE64_32_BYTE_KEY"
ota_password: "REPLACE_ME_OTA_PASSWORD"
device_name: "esp32-s3-box-3-kitchen"
device_friendly_name: "Kitchen Voice Satellite"
```

What each value is for:

- `wifi_ssid`: the Wi-Fi network name the ESP32-S3-BOX-3 should join
- `wifi_password`: the password for that Wi-Fi network
- `api_encryption_key`: the ESPHome native API encryption key used between the device and Home Assistant
- `ota_password`: the password used when uploading new firmware over ESPHome OTA
- `device_name`: optional per-device ESPHome node name if you want a fixed custom identity
- `device_friendly_name`: optional Home Assistant display name paired with `device_name`

Notes:

- `src/esphome/secrets.yaml` is ignored by git and should contain your real values
- `src/esphome/secrets.example.yaml` is the safe template committed to the repo

## Device Naming Approaches

This project supports two practical ways to name devices on the same network.

### Approach 1: Automatic unique fallback

The default firmware enables:

```yaml
esphome:
  name_add_mac_suffix: true
```

That means the compiled base name:

```yaml
name: esp32-s3-box-3-voice
```

becomes a stable unique device name such as:

```text
esp32-s3-box-3-voice-a1b2c3
```

This is the safest fallback for multiple devices because it remains stable for
the same hardware across power cycles.

### Approach 2: Fixed per-device names from `secrets.yaml`

If you want a custom fixed name per unit, set these values in:

- `src/esphome/secrets.yaml`

Example:

```yaml
device_name: "esp32-s3-box-3-kitchen"
device_friendly_name: "Kitchen Voice Satellite"
```

Then update `src/esphome/esp32-s3-box-3-voice.yaml` substitutions from:

```yaml
name: esp32-s3-box-3-voice
friendly_name: ESP32-S3-BOX-3 Voice
```

to:

```yaml
name: !secret device_name
friendly_name: !secret device_friendly_name
```

Use this approach when you want predictable names like `kitchen`, `office`, or
`bedroom` instead of MAC-based suffixes.

## Display Asset And Visual States

The firmware uses a compile-time-selected face image for the on-screen visual:

- HAL face asset: `src/esphome/assets/HAL_200x200.png`
- Alien face asset: `src/esphome/assets/ALIEN_200x200.png`
- theme selector: `src/esphome/face-theme-params.yaml`

Current expected asset format:

- `PNG`
- `200x200`
- `RGBA` with transparency supported

How it is used:

- idle state: the selected image is used as the clock background
- idle green mode: Home Assistant can optionally tint the idle clock face green
- listening state: the selected image is shown in the center with pulse animation and no tint
- responding state: the selected image is shown in the center with pulse animation and a blue tint
- error state: the selected image is shown in the center with pulse animation and a white tint

Build-time controls:

- `src/esphome/face-theme-params.yaml`
  - `face_frame_interval_ms`: intended array animation timing value
  - `idle_use_clock`: enables or disables the idle clock overlay

Alien theme note:

- when `face_theme` is set to `ALIEN`, the listening visual is tinted green

Future frame-array placeholders are scaffolded under:

- `src/esphome/assets/face-arrays/HAL/`
- `src/esphome/assets/face-arrays/ALIEN/`

Related files:

- firmware behavior: `src/esphome/esp32-s3-box-3-voice.yaml`
- HAL preview: `preview/index.html`
- theme-array preview: `preview-faces/index.html`

If you replace the active asset selected in `src/esphome/face-theme-params.yaml`,
both the firmware display and the corresponding preview will use the updated face.

## Home Assistant Controlled Clock Tint

The firmware can change the idle clock face to a green tint from Home Assistant
without recompiling after this feature is flashed once.

It reads this Home Assistant entity through the ESPHome native API:

- `input_boolean.voice_clock_green`

Behavior:

- `off`: normal idle clock image
- `on`: idle clock image gets a green tint

This is implemented in:

- `src/esphome/esp32-s3-box-3-voice.yaml`

Create the helper in Home Assistant if it does not already exist:

1. Go to `Settings`
2. Go to `Devices & Services`
3. Go to `Helpers`
4. Create an `Input boolean`
5. Name it `voice_clock_green`

You can then toggle it manually or from any Home Assistant automation.

Example automation:

```yaml
alias: Turn Voice Clock Green When Condition Is Met
description: Example automation for toggling the idle clock tint
trigger:
  - platform: numeric_state
    entity_id: sensor.some_value
    above: 50
action:
  - service: input_boolean.turn_on
    target:
      entity_id: input_boolean.voice_clock_green
mode: single
```

Example reset automation:

```yaml
alias: Turn Voice Clock Green Off When Condition Clears
description: Example automation for restoring the normal idle clock tint
trigger:
  - platform: numeric_state
    entity_id: sensor.some_value
    below: 50
action:
  - service: input_boolean.turn_off
    target:
      entity_id: input_boolean.voice_clock_green
mode: single
```

## Compile The Firmware

From the repository root:

```bash
cd src/esphome
esphome compile esp32-s3-box-3-voice.yaml
```

That will validate the YAML and build the firmware binary.

## First Upload Over USB

For the first install, connect the BOX-3 over USB and run:

```bash
cd src/esphome
esphome run esp32-s3-box-3-voice.yaml --device /dev/ttyACM0
```

If your serial device is different, replace `/dev/ttyACM0` with the correct
path such as `/dev/ttyUSB0`.

You can also split compile and upload:

```bash
cd src/esphome
esphome compile esp32-s3-box-3-voice.yaml
esphome upload esp32-s3-box-3-voice.yaml --device /dev/ttyACM0
```

## OTA Upload After First Flash

Yes. The current firmware already includes standard ESPHome OTA support:

- `api:` is enabled for Home Assistant connectivity
- `ota:` with `platform: esphome` is enabled for standard ESPHome OTA updates

After the device has been flashed once and joined Wi-Fi, you can upload new
firmware over the network:

```bash
cd src/esphome
esphome run esp32-s3-box-3-voice.yaml
```

Or explicitly:

```bash
cd src/esphome
esphome upload esp32-s3-box-3-voice.yaml --device esp32-s3-box-3-voice.local
```

If mDNS does not resolve on your network, use the device IP instead of
`esp32-s3-box-3-voice.local`.

## Binary Location

After a successful compile, ESPHome stores build output under:

- `src/esphome/.esphome/`

If you need the generated firmware artifact for manual flashing, use the build
output from that directory.

## Home Assistant Notes

- Home Assistant handles the Assist pipeline.
- This firmware is the voice endpoint only.
- Whisper, Piper, openWakeWord, and Ollama are expected to be configured on the
  Home Assistant side, not in ESPHome.

## Recommended Workflow

1. Edit `src/esphome/secrets.yaml`.
2. Confirm the selected face asset is present in `src/esphome/assets/`.
3. Compile the firmware.
4. Flash once over USB.
5. Perform future updates over standard ESPHome OTA.
