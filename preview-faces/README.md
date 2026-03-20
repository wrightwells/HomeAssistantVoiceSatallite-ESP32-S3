# Theme Array Preview

This second preview app models the newer face system:

- compile-time theme selection between `HAL` and `ALIEN`
- per-state image-array placeholders
- the same interaction color behavior as the firmware
- idle clock overlay support
- interactive clock on/off button in the preview UI

## Run

From the repository root:

```bash
python3 -m http.server 8001
```

Then open:

```text
http://127.0.0.1:8001/preview-faces/
```

To stop the server, return to the terminal and press:

```text
Ctrl+C
```

## What It Uses

- `src/esphome/assets/HAL_200x200.png`
- `src/esphome/assets/ALIEN_200x200.png`

## Array Placeholders

Future multi-frame arrays can be added under:

- `src/esphome/assets/face-arrays/HAL/`
- `src/esphome/assets/face-arrays/ALIEN/`

Right now each state uses the first frame only and changes color by state:

Right now the Alien theme is normalized to 6 frames in every state:

- idle: uses the sleeping/dreaming 300x200 frame array
- listening: uses the quizzical 6-frame listening array and shows green tint
- responding: uses the talking 6-frame response array with blue state tint
- error: uses a 6-frame placeholder array built from the static Alien face

Preview tuning defaults mirror:

- `src/esphome/face-theme-params.yaml`
  - `face_frame_interval_ms`
  - `idle_use_clock`
