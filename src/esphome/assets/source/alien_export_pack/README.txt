AI face export pack

Files:
- ai_face_rgb565.h
  Plain 16-bit RGB565 sprite as uint16_t[40000].
  Transparency is flattened to black.
- ai_face_mask_1bit.h
  1-bit alpha mask for the RGB565 sprite.
- ai_face_lvgl.c
  LVGL image array using 16-bit TRUE_COLOR_ALPHA (RGB565 + alpha).
- ai_face_lvgl_swapped.c
  Same as above, but with RGB565 bytes swapped.

Notes:
- Image size: 200x200
- For LVGL, use ai_face first.
- If colors look wrong on your panel, try ai_face_swapped or enable LV_COLOR_16_SWAP.
- For very constrained ESP32 builds, the plain RGB565 sprite plus 1-bit mask is lighter than full LVGL alpha.

Example LVGL usage:
    LV_IMG_DECLARE(ai_face);
    lv_obj_t * img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &ai_face);

Example raw sprite usage:
    // draw ai_face_rgb565[] and optionally skip pixels where the mask bit is 0
