/*
	csspid.h
	Copyright(c) 1996-2006 ACCESS CO., LTD.
	All rights are reserved by ACCESS CO., LTD., whether the whole or
	part of the source code including any modifications.
*/

/* $Header: /SpinningWheel/slim/slim/private/token/csspid.h 7     06/07/11 2:23 Yamabuti $ */

/* DO NOT EDIT! This file is generated automagically. */

#ifndef SLIM_TOKEN_CSSPID_H
#define SLIM_TOKEN_CSSPID_H


SLIM_BEGIN_C_LINKAGE

enum {
	SLIM_TKID_CSSP_background = 0,
	SLIM_TKID_CSSP_background_attachment,
	SLIM_TKID_CSSP_background_color,
	SLIM_TKID_CSSP_background_image,
	SLIM_TKID_CSSP_background_position,
	SLIM_TKID_CSSP_background_repeat,
	SLIM_TKID_CSSP_border,
	SLIM_TKID_CSSP_border_bottom,
	SLIM_TKID_CSSP_border_bottom_width,
	SLIM_TKID_CSSP_border_color,
	SLIM_TKID_CSSP_border_left,
	SLIM_TKID_CSSP_border_left_width,
	SLIM_TKID_CSSP_border_right,
	SLIM_TKID_CSSP_border_right_width,
	SLIM_TKID_CSSP_border_style,
	SLIM_TKID_CSSP_border_top,
	SLIM_TKID_CSSP_border_top_width,
	SLIM_TKID_CSSP_border_width,
	SLIM_TKID_CSSP_color,
	SLIM_TKID_CSSP_font,
	SLIM_TKID_CSSP_font_family,
	SLIM_TKID_CSSP_font_size,
	SLIM_TKID_CSSP_font_style,
	SLIM_TKID_CSSP_font_variant,
	SLIM_TKID_CSSP_font_weight,
	SLIM_TKID_CSSP_height,
	SLIM_TKID_CSSP_list_style,
	SLIM_TKID_CSSP_list_style_image,
	SLIM_TKID_CSSP_list_style_position,
	SLIM_TKID_CSSP_list_style_type,
	SLIM_TKID_CSSP_margin,
	SLIM_TKID_CSSP_margin_bottom,
	SLIM_TKID_CSSP_margin_left,
	SLIM_TKID_CSSP_margin_right,
	SLIM_TKID_CSSP_margin_top,
	SLIM_TKID_CSSP_padding,
	SLIM_TKID_CSSP_padding_bottom,
	SLIM_TKID_CSSP_padding_left,
	SLIM_TKID_CSSP_padding_right,
	SLIM_TKID_CSSP_padding_top,
	SLIM_TKID_CSSP_text_align,
	SLIM_TKID_CSSP_text_decoration,
	SLIM_TKID_CSSP_text_indent,
	SLIM_TKID_CSSP_text_transform,
	SLIM_TKID_CSSP_vertical_align,
	SLIM_TKID_CSSP_white_space,
	SLIM_TKID_CSSP_width,
	SLIM_TKID_CSSP_display,
	SLIM_TKID_CSSP_clear,
	SLIM_TKID_CSSP_float,
	SLIM_TKID_CSSP_letter_spacing,
	SLIM_TKID_CSSP_line_height,
	SLIM_TKID_CSSP_word_spacing,
	SLIM_TKID_CSSP_border_bottom_color,
	SLIM_TKID_CSSP_border_bottom_style,
	SLIM_TKID_CSSP_border_left_color,
	SLIM_TKID_CSSP_border_left_style,
	SLIM_TKID_CSSP_border_right_color,
	SLIM_TKID_CSSP_border_right_style,
	SLIM_TKID_CSSP_border_top_color,
	SLIM_TKID_CSSP_border_top_style,
	SLIM_TKID_CSSP_font_size_adjust,
	SLIM_TKID_CSSP_font_stretch,
	SLIM_TKID_CSSP__wap_marquee_style,
	SLIM_TKID_CSSP__wap_marquee_loop,
	SLIM_TKID_CSSP__wap_marquee_dir,
	SLIM_TKID_CSSP__wap_marquee_speed,
	SLIM_TKID_CSSP__wap_accesskey,
	SLIM_TKID_CSSP__wap_input_format,
	SLIM_TKID_CSSP__wap_input_required,
#ifdef SLIM_CONFIG_CSS_EXTENSION_BROADCAST
	SLIM_TKID_CSSP_used_key_list,
	SLIM_TKID_CSSP_resolution,
	SLIM_TKID_CSSP_resolution_width,
	SLIM_TKID_CSSP_resolution_height,
#endif /* SLIM_CONFIG_CSS_EXTENSION_BROADCAST */
#ifdef SLIM_CONFIG_CSS_LEVEL_1_POSITIONING
	SLIM_TKID_CSSP_bottom,
	SLIM_TKID_CSSP_clip,
	SLIM_TKID_CSSP_left,
	SLIM_TKID_CSSP_overflow,
	SLIM_TKID_CSSP_position,
	SLIM_TKID_CSSP_right,
	SLIM_TKID_CSSP_top,
	SLIM_TKID_CSSP_visibility,
	SLIM_TKID_CSSP_z_index,
#endif /* SLIM_CONFIG_CSS_LEVEL_1_POSITIONING */
#ifdef SLIM_CONFIG_CSS_LEVEL_2
	SLIM_TKID_CSSP_border_collapse,
	SLIM_TKID_CSSP_border_spacing,
	SLIM_TKID_CSSP_caption_side,
	SLIM_TKID_CSSP_direction,
	SLIM_TKID_CSSP_empty_cells,
	SLIM_TKID_CSSP_marker_offset,
	SLIM_TKID_CSSP_max_height,
	SLIM_TKID_CSSP_max_width,
	SLIM_TKID_CSSP_min_height,
	SLIM_TKID_CSSP_min_width,
	SLIM_TKID_CSSP_quotes,
	SLIM_TKID_CSSP_table_layout,
	SLIM_TKID_CSSP_text_shadow,
	SLIM_TKID_CSSP_unicode_bidi,
	SLIM_TKID_CSSP_cursor,
	SLIM_TKID_CSSP_outline,
	SLIM_TKID_CSSP_outline_color,
	SLIM_TKID_CSSP_outline_style,
	SLIM_TKID_CSSP_outline_width,
	SLIM_TKID_CSSP_marks,
	SLIM_TKID_CSSP_orphans,
	SLIM_TKID_CSSP_page,
	SLIM_TKID_CSSP_page_break_after,
	SLIM_TKID_CSSP_page_break_before,
	SLIM_TKID_CSSP_page_break_inside,
	SLIM_TKID_CSSP_size,
	SLIM_TKID_CSSP_widows,
	SLIM_TKID_CSSP_content,
	SLIM_TKID_CSSP_counter_increment,
	SLIM_TKID_CSSP_counter_reset,
#endif /* SLIM_CONFIG_CSS_LEVEL_2 */
#ifdef SLIM_CONFIG_CSS_LEVEL_2_WITH_AURAL
	SLIM_TKID_CSSP_azimuth,
	SLIM_TKID_CSSP_cue,
	SLIM_TKID_CSSP_cue_after,
	SLIM_TKID_CSSP_cue_before,
	SLIM_TKID_CSSP_elevation,
	SLIM_TKID_CSSP_pause,
	SLIM_TKID_CSSP_pause_after,
	SLIM_TKID_CSSP_pause_before,
	SLIM_TKID_CSSP_pitch,
	SLIM_TKID_CSSP_pitch_range,
	SLIM_TKID_CSSP_play_during,
	SLIM_TKID_CSSP_richness,
	SLIM_TKID_CSSP_speak,
	SLIM_TKID_CSSP_speak_header,
	SLIM_TKID_CSSP_speak_numeral,
	SLIM_TKID_CSSP_speak_punctuation,
	SLIM_TKID_CSSP_speech_rate,
	SLIM_TKID_CSSP_stress,
	SLIM_TKID_CSSP_voice_family,
	SLIM_TKID_CSSP_volume,
#endif /* SLIM_CONFIG_CSS_LEVEL_2_WITH_AURAL */
#ifdef SLIM_CONFIG_CSS_LEVEL_3
	SLIM_TKID_CSSP_box_sizing,
	SLIM_TKID_CSSP_opacity,
	SLIM_TKID_CSSP_overflow_x,
	SLIM_TKID_CSSP_overflow_y,
#endif /* SLIM_CONFIG_CSS_LEVEL_3 */
	SLIM_TKID_CSSP_ENUMS
};

#define SLIM_TOKEN_CSSP_TOKENS SLIM_TKID_CSSP_ENUMS
#define SLIM_TOKEN_CSSP_ENUMS SLIM_TKID_CSSP_ENUMS


SLIM_END_C_LINKAGE
#endif
