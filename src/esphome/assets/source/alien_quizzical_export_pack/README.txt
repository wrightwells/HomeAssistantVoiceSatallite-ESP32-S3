AI face quizzical / listening animation export pack

Contents:
- quizzical_frame_*.png                Transparent source frames
- ai_face_quizzical.gif                Preview animation
- ai_face_quizzical_*.c                LVGL true-color-alpha image arrays
- ai_face_quizzical_*_rgb565.h         Raw RGB565 sprite arrays
- ai_face_quizzical_*_mask_1bit.h      1-bit alpha masks
- ai_face_quizzical_anim.h             Convenience LVGL declarations array

Expression style:
- raised asymmetric brows
- curious mouth changes
- optional thinking dots
- subtle loop suitable for listening / processing state

Suggested loop timing:
- 90 to 130 ms per frame

Example LVGL frame cycling:
    static uint8_t idx = 0;
    lv_img_set_src(img, ai_face_quizzical_frames[idx]);
    idx = (idx + 1) % AI_FACE_QUIZZICAL_FRAME_COUNT;
