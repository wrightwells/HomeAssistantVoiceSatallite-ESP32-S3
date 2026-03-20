# ESPHome Setup

## Scope

This project treats the ESP32-S3-BOX-3 as a lean voice endpoint for Home
Assistant Assist. Whisper, Piper, openWakeWord, and Ollama remain configured on
the Home Assistant side.

## Local files

- firmware: `src/esphome/esp32-s3-box-3-voice.yaml`
- face theme config: `src/esphome/face-theme-params.yaml`
- local secrets: `src/esphome/secrets.yaml`
- HAL asset: `src/esphome/assets/HAL_200x200.png`
- Alien asset: `src/esphome/assets/ALIEN_200x200.png`

## Home Assistant expectations

- native ESPHome API connection to Home Assistant
- Assist pipeline configured in Home Assistant
- preferred local services hosted at `10.10.20.210`

## Verify on first boot

- display initializes and backlight turns on
- microphone captures speech
- speaker plays Assist responses
- mute, volume, and restart entities appear in Home Assistant
- wake word mode behaves as expected
