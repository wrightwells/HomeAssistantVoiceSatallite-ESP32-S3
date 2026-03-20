# ESPHome Firmware

This directory contains the production-oriented ESPHome scaffold for the
ESP32-S3-BOX-3 Home Assistant voice satellite.

## Files

- `esp32-s3-box-3-voice.yaml`: main firmware configuration
- `face-theme-params.yaml`: face, clock, and animation build parameters
- `secrets.example.yaml`: template for local secrets
- `assets/`: display image assets referenced by the YAML

## Quick start

1. Copy `secrets.example.yaml` to `secrets.yaml`.
2. Replace the placeholder values in `secrets.yaml`.
3. Select the active face in `face-theme-params.yaml`.
4. Tune clock/animation behavior in `face-theme-params.yaml` if needed.
5. Confirm the matching asset exists in `assets/`.
6. Compile/upload with ESPHome from this directory.

## Wake word modes

Preferred mode is on-device wake word using `micro_wake_word`.

Fallback mode is Home Assistant server-side wake word. To switch:

- comment out the `micro_wake_word:` block
- remove `micro_wake_word: box_mww` from `voice_assistant`
- set `use_wake_word: true`
- replace `micro_wake_word.start:` with `voice_assistant.start_continuous:`
- replace `micro_wake_word.stop:` calls with `voice_assistant.stop:`
