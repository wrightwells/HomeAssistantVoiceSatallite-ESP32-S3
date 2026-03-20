# HomeAssistantVoiceSatallite-ESP32-S3

ESPHome firmware project for an `ESP32-S3-BOX-3` acting as a lean Home
Assistant Assist voice satellite.

## What Is In This Repo

- firmware YAML: `src/esphome/esp32-s3-box-3-voice.yaml`
- local secrets template: `src/esphome/secrets.example.yaml`
- display asset folder: `src/esphome/assets/`
- setup notes: `docs/esphome-setup.md`

## Requirements

- ESPHome installed locally or available through a standard ESPHome install
- an `ESP32-S3-BOX-3`
- USB connection for the first flash
- Home Assistant reachable on your network

## Prepare The Config

1. Copy `src/esphome/secrets.example.yaml` to `src/esphome/secrets.yaml`.
2. Replace the placeholder Wi-Fi, API, and OTA values in `src/esphome/secrets.yaml`.
3. Place the pulse image at `src/esphome/assets/voice_pulse.png`.

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
```

What each value is for:

- `wifi_ssid`: the Wi-Fi network name the ESP32-S3-BOX-3 should join
- `wifi_password`: the password for that Wi-Fi network
- `api_encryption_key`: the ESPHome native API encryption key used between the device and Home Assistant
- `ota_password`: the password used when uploading new firmware over ESPHome OTA

Notes:

- `src/esphome/secrets.yaml` is ignored by git and should contain your real values
- `src/esphome/secrets.example.yaml` is the safe template committed to the repo

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
2. Confirm `src/esphome/assets/voice_pulse.png` is present.
3. Compile the firmware.
4. Flash once over USB.
5. Perform future updates over standard ESPHome OTA.
