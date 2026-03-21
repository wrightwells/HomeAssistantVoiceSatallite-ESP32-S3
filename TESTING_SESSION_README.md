# Testing Session Prompt

Use the prompt below when starting a future coding or debugging session for this repo.

```text
You are helping with the repo HomeAssistantVoiceSatallite-ESP32-S3.

Current goal:
- Validate and tune ESPHome firmware for an ESP32-S3-BOX-3 Home Assistant Assist voice satellite.
- Focus on real hardware behavior, especially display performance, audio stability, wake word response, and LVGL compatibility.

Repo summary:
- Main firmware YAML:
  - src/esphome/esp32-s3-box-3-voice.yaml
- Build parameter files:
  - src/esphome/face-theme-params.yaml
  - src/esphome/clock-params.yaml
- Main docs:
  - README.md
  - docs/esphome-setup.md
  - src/esphome/README.md
- Browser previews:
  - preview/index.html
  - preview-faces/index.html

Current firmware design:
- ESP32-S3-BOX-3 voice satellite for Home Assistant Assist
- Uses native ESPHome API, OTA, built-in mic/speaker assumptions, LVGL display
- Wake word path prefers on-device micro_wake_word
- HAL theme stays on the lean single-image path
- ALIEN theme now uses LVGL animimg on-device for:
  - idle
  - listening
  - responding
  - error
- Idle clock overlay is optional through build parameters

Theme and animation details:
- Compile-time theme switch is in src/esphome/face-theme-params.yaml
- HAL assets:
  - src/esphome/assets/HAL_200x200.png
- ALIEN base asset:
  - src/esphome/assets/ALIEN_200x200.png
- ALIEN animation frame arrays:
  - src/esphome/assets/face-arrays/ALIEN/idle
  - src/esphome/assets/face-arrays/ALIEN/listening
  - src/esphome/assets/face-arrays/ALIEN/responding
  - src/esphome/assets/face-arrays/ALIEN/error

State behavior expected on hardware:
- idle:
  - HAL: static centered face with optional clock overlay
  - ALIEN: animimg idle frames with optional clock overlay
- listening:
  - HAL: single-image pulse with no tint
  - ALIEN: animimg listening frames tinted green
- responding:
  - HAL: single-image pulse tinted blue
  - ALIEN: animimg responding frames tinted blue
- error:
  - HAL: single-image pulse tinted white
  - ALIEN: animimg error frames tinted white

Important Home Assistant integration:
- input_boolean.voice_clock_green is imported into ESPHome and can tint the idle face green without recompiling
- Home Assistant supplies time for the idle clock
- Home Assistant handles the Assist pipeline, not the ESP32 directly

Known uncertainties / things to test carefully:
- Exact ESP32-S3-BOX-3 pin assumptions for display/audio codecs
- Current ESPHome compatibility for this YAML, especially LVGL animimg actions and style updates
- Performance impact of ALIEN animated frames with voice_assistant + micro_wake_word enabled
- Memory pressure from multiple 300x200 RGB565+alpha images
- Whether animimg recolor behaves as expected on-device
- Whether the idle clock aligns correctly over both HAL and ALIEN themes

Requested help during testing:
- Validate compile errors first
- Fix any ESPHome syntax drift against current official docs
- Help optimize performance conservatively for hardware stability
- Prefer correctness and deployability over flashy UI
- Keep HAL as the low-risk fallback path if ALIEN animation is too heavy

If there are runtime issues, start by inspecting:
- src/esphome/esp32-s3-box-3-voice.yaml
- src/esphome/face-theme-params.yaml
- src/esphome/clock-params.yaml
- preview-faces/index.html
```

## Notes

- This file is a handoff prompt for future sessions.
- It is intended to save time when moving from design work to real BOX-3 hardware testing.
- Update it whenever the firmware architecture changes in a meaningful way.
