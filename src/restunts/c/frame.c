#include "externs.h"
#include "math.h"
#include "shape3d.h"

#define TILES_TO_DRAW_WIDTH 11  // odd is better
#define TILES_TO_DRAW_DEPTH 10
#define TILES_TO_DRAW_COUNT TILES_TO_DRAW_WIDTH * TILES_TO_DRAW_DEPTH

extern struct RECTANGLE* rectptr_unk2;
extern struct RECTANGLE rect_array_unk[];
extern struct RECTANGLE rect_array_unk2[];
extern struct RECTANGLE rect_unk[];
extern struct RECTANGLE rect_unk2;
extern struct RECTANGLE rect_unk6;
extern struct RECTANGLE rect_unk9;
extern struct RECTANGLE rect_unk11;
extern struct RECTANGLE rect_unk12;
extern struct RECTANGLE rect_unk15;
extern struct RECTANGLE cliprect_unk;
extern struct VECTOR vec_unk2;
extern struct VECTOR vec_planerotopresult;
extern struct MATRIX mat_temp;
extern int word_3B8EC;
extern int word_3B8F0;
extern int word_3B8EE;
extern int word_44D20;
extern char detail_threshold_by_level[];
extern char byte_3C0C6[];
extern char word_46468;
extern int word_3BE34[];
extern char* tiles_to_draw_offsets_tables[];
extern struct SHAPE3D* off_3BE44[];
extern int terrainHeight;
extern int planindex;
extern int planindex_copy;
extern char byte_4392C;
extern struct TRANSFORMEDSHAPE3D currenttransshape[TILES_TO_DRAW_COUNT + 5];
//extern struct TRANSFORMEDSHAPE3D transshapeunk;
extern struct TRANSFORMEDSHAPE3D* curtransshape_ptr;
extern struct TRACKOBJECT trkObjectList[215]; // 215 entries
extern unsigned char fence_TrkObjCodes[];
extern int pState_minusRotate_z_2, pState_minusRotate_x_2, pState_minusRotate_y_2, pState_f36Mminf40sar2;

extern char unk_3C0EE[];
extern char unk_3C0F0[];
extern char unk_3C0F8[];
extern char unk_3C0F4[];
extern int word_3C0D6[];
extern int unk_3C0A2[];
extern int unk_3C0A6[];
extern int unk_3C0AE[];
extern int unk_3C0B6[];
extern struct TRACKOBJECT sceneshapes2[];
extern struct TRACKOBJECT sceneshapes3[];
extern struct SHAPE3D game3dshapes[130];
extern struct VECTOR carshapevec;
extern struct VECTOR carshapevecs[6];
extern short word_443E8[];
extern struct VECTOR oppcarshapevec;
extern struct VECTOR oppcarshapevecs[6];
extern short word_4448A[];
extern char backlights_paint_override;
extern int word_449FC[];
extern int word_463D6;
extern int transformedshape_zarray[TILES_TO_DRAW_COUNT + 5];
extern int transformedshape_indices[TILES_TO_DRAW_COUNT + 5];
extern char transformedshape_arg2array[TILES_TO_DRAW_COUNT + 5];
extern int sdgame2_widths[];
extern void far* sdgame2shapes[];
extern void far* fontledresptr;
extern int dialog_fnt_colour;
extern char transformedshape_counter;

void build_track_object(struct VECTOR* a, struct VECTOR* b);
void transformed_shape_add_for_sort(int a, int b);
unsigned char subst_hillroad_track(unsigned char a, unsigned char b);
int skybox_op(int a, struct RECTANGLE* rectptr, int c, struct MATRIX* matptr, int e, int f, int g);
struct RECTANGLE* draw_ingame_text(void);
struct RECTANGLE* init_crak(int frame, int top, int height);
struct RECTANGLE* do_sinking(int frame, int top, int height);
struct RECTANGLE* intro_draw_text(char* str, int a, int b, int c, int d);
void font_set_fontdef2(void far* data);
void format_frame_as_string(char* s, int time, int c);
void shape_op_explosion(int a, void far* shp, int x, int y);
void heapsort_by_order(int n, int* heap, int* data);

void update_frame(char arg_0, struct RECTANGLE* arg_cliprectptr) {
	int si;
	char var_122;
	char var_E4;
	char var_DC[2];
	struct RECTANGLE* var_rectptr;
	struct MATRIX var_mat, var_mat2;
	struct MATRIX* car_rot_matrix;
	struct VECTOR cam_pos, car_pos, car_to_cam_abs, car_to_cam_rotated, var_vec8;
	int car_rot_y, car_rot_x, car_rot_z;
	int car_rot_y_2, car_rot_x_2, car_rot_z_2;
	int var_38, car_rot_z_3;
	int var_transformresult;
	int heading;
	char* tiles_to_draw_offsets;
	int var_2;
	int var_counter, var_counter2;
	char cam_tile_negz, cam_tile_x;
	char tile_to_draw_negz, tile_to_draw_x;
	char tile_to_draw_y_offset, tile_to_draw_x_offset_2;
	char car_tile_x, car_tile_y;
	unsigned char tiles_to_draw_terr_type_vec[TILES_TO_DRAW_COUNT];
	char var_32[TILES_TO_DRAW_COUNT];
	char tile_detail_level_vec[TILES_TO_DRAW_COUNT];
	char tiles_to_draw_y_vec[TILES_TO_DRAW_COUNT];
	char tiles_to_draw_x_vec[TILES_TO_DRAW_COUNT];
	unsigned char tiles_to_draw_elem_type_vec[TILES_TO_DRAW_COUNT];
	char detail_threshold;
	char var_3C;
	char var_60;
	char var_6E;
	char var_4A;
	char var_4E;
	int var_6C;
	int var_A4;
	int var_hillheight;
	int idx;
	struct TRACKOBJECT* var_trkobjectptr;
	struct TRACKOBJECT* var_trkobject_ptr; // NOTE: beware of similar names!!
	char tile_det_level;
	char* var_10E;
	int di;
	int var_132;
	int var_5E;
	int var_3A;
	int* var_DA;
	int var_12A;
	unsigned char var_4C;
	struct RECTANGLE var_rect, var_rect2;
	struct VECTOR far* var_108;
	struct CARSTATE* var_stateptr;
	unsigned char elem_map_value;
	unsigned char terr_map_value;

	char tiles_to_draw_offset_depth;
	char tiles_to_draw_offset_width;
	char depth_to_x;
	char depth_to_negz;
	char width_to_x;
	char width_to_negz;
	char width_idx;

	var_DC[0] = 0;
	var_DC[1] = 0;
	if (video_flag5_is0 == 0 || arg_0 == 0) {
		rectptr_unk = rect_array_unk;
		rectptr_unk2 = rect_array_unk2;
	} else {
		rectptr_unk2 = rect_array_unk;
		rectptr_unk = rect_array_unk2;
	}

	if (timertestflag_copy != 0) {
		var_122 = 8;
		var_rectptr = rect_unk;
		for (si = 0; si < 15; si++) {
			*var_rectptr = cliprect_unk;
			var_rectptr++;
		}
	} else {
		var_122 = 0;
	}

	if (followOpponentFlag == 0) {
		car_pos.x = state.playerstate.car_posWorld1.lx >> 6;
		car_pos.y = state.playerstate.car_posWorld1.ly >> 6;
		car_pos.z = state.playerstate.car_posWorld1.lz >> 6;
		car_rot_y = state.playerstate.car_rotate.y;
		car_rot_z = state.playerstate.car_rotate.z;
		car_rot_x = state.playerstate.car_rotate.x;
	} else {
		car_pos.x = state.opponentstate.car_posWorld1.lx >> 6;
		car_pos.y = state.opponentstate.car_posWorld1.ly >> 6;
		car_pos.z = state.opponentstate.car_posWorld1.lz >> 6;
		car_rot_y = state.opponentstate.car_rotate.y;
		car_rot_z = state.opponentstate.car_rotate.z;
		car_rot_x = state.opponentstate.car_rotate.x;
	}

	car_rot_x_2 = -1;
	car_rot_z_2 = 0;

	if (cameramode == 0) {
		car_rot_x_2 = car_rot_x & 0x3ff;
		car_rot_y_2 = car_rot_y & 0x3ff;
		car_rot_z_2   = car_rot_z & 0x3ff;
		car_rot_matrix = mat_rot_zxy(-car_rot_z, -car_rot_y, -car_rot_x, 0);
		car_to_cam_abs.x = 0;
		car_to_cam_abs.z = 0;
		car_to_cam_abs.y = simd_player.car_height - 6;

		mat_mul_vector(&car_to_cam_abs, car_rot_matrix, &car_to_cam_rotated);
		cam_pos.x = car_pos.x + car_to_cam_rotated.x;
		cam_pos.y = car_pos.y + car_to_cam_rotated.y;
		cam_pos.z = car_pos.z + car_to_cam_rotated.z;
	} else if (cameramode == 1) {
		cam_pos.x = state.game_vec1[followOpponentFlag].x;
		cam_pos.z = state.game_vec1[followOpponentFlag].z;
		cam_pos.y = state.game_vec1[followOpponentFlag].y;
	} else if (cameramode == 2) {
		car_to_cam_abs.x = 0;
		car_to_cam_abs.y = 0;
		car_to_cam_abs.z = 0x4000;
		car_rot_matrix = mat_rot_zxy(-car_rot_z, -car_rot_y, -car_rot_x, 0);
		mat_mul_vector(&car_to_cam_abs, car_rot_matrix, &car_to_cam_rotated);

		car_to_cam_abs.x = 0;
		car_to_cam_abs.y = 0;
		car_to_cam_abs.z = word_3B8EC;
		car_rot_matrix = mat_rot_zxy(0, -word_3B8F0, polarAngle(car_to_cam_rotated.x, car_to_cam_rotated.z) - word_3B8EE, 0);

		mat_mul_vector(&car_to_cam_abs, car_rot_matrix, &car_to_cam_rotated);
		cam_pos.x = car_pos.x + car_to_cam_rotated.x;
		cam_pos.y = car_pos.y + car_to_cam_rotated.y;
		cam_pos.z = car_pos.z + car_to_cam_rotated.z;
	} else if (cameramode == 3) {
		cam_pos.x = trackdata9[state.field_3F7[followOpponentFlag] * 3 + 0];
		cam_pos.y = trackdata9[state.field_3F7[followOpponentFlag] * 3 + 1] + word_44D20 + 0x5A;
		cam_pos.z = trackdata9[state.field_3F7[followOpponentFlag] * 3 + 2];
	}

	if (car_rot_x_2 == -1) {
		build_track_object(&cam_pos, &cam_pos);
		if (cam_pos.y < terrainHeight) {
			cam_pos.y = terrainHeight;
		}

		if (byte_4392C != 0) {
			si = plane_origin_op(planindex, cam_pos.x, cam_pos.y, cam_pos.z);
			if (si < 0xC) {
				vec_unk2.x = 0;
				vec_unk2.y = 0xC - si;
				vec_unk2.z = 0;
				planindex_copy = planindex;
				pState_f36Mminf40sar2 = 0;
				pState_minusRotate_x_2 = 0;
				pState_minusRotate_z_2 = 0;
				pState_minusRotate_y_2 = 0;
				plane_rotate_op();
				cam_pos.x += vec_planerotopresult.x;
				cam_pos.y += vec_planerotopresult.y;
				cam_pos.z += vec_planerotopresult.z;
			}
		}

		car_rot_x_2 = (-polarAngle(car_pos.x - cam_pos.x, car_pos.z - cam_pos.z)) & 0x3FF;
		var_38 = polarRadius2D(car_pos.x - cam_pos.x, car_pos.z - cam_pos.z);
		car_rot_y_2 = polarAngle(car_pos.y - cam_pos.y + 0x32, var_38) & 0x3FF;
	}

	if (car_rot_z_2 > 1 && car_rot_z_2 < 0x3FF) {
		car_rot_z_3 = car_rot_z_2;
	} else {
		car_rot_z_3 = 0;
	}

	if (state.game_frame == 0) {
		var_E4 = byte_3C0C6[word_46468&0xF];
	} else {
		var_E4 = byte_3C0C6[state.game_frame&0xF];
	}

	heading = select_cliprect_rotate(car_rot_z_3, car_rot_y_2, car_rot_x_2, arg_cliprectptr, 0);
	tiles_to_draw_offsets = tiles_to_draw_offsets_tables[(heading & 0x3FF) >> 7]; //off_3C084[(var_52 & 0x3FF) >> 7];

	var_mat = *mat_rot_zxy(car_rot_z_3, car_rot_y_2, 0, 1);
	car_to_cam_abs.x = 0;
	car_to_cam_abs.y = 0;
	car_to_cam_abs.z = 0x3E8;
	mat_mul_vector(&car_to_cam_abs, &var_mat, &var_vec8);
	if (var_vec8.z > 0) {
		var_2 = 1;
	} else {
		var_2 = -1;
	}

	if (detail_level == 0) {
		currenttransshape->rectptr = &rect_unk9;
		currenttransshape->ts_flags = var_122 | 7;
		currenttransshape->rotvec.x = 0;
		currenttransshape->rotvec.y = 0;
		currenttransshape->unk = 0x400;
		currenttransshape->material = 0;

		for (var_counter = 0; var_counter < 8; var_counter++) {
			si = (word_3BE34[var_counter] + car_rot_x_2 + run_game_random) & 0x3ff;
			if (si < 0x87 || si > 0x379) {
				mat_rot_y(&var_mat2, si);
				car_to_cam_abs.x = 0;
				car_to_cam_abs.y = 0xAE6 - cam_pos.y;
				car_to_cam_abs.z = 0x3A98; //15000
				mat_mul_vector(&car_to_cam_abs, &var_mat2, &car_to_cam_rotated);
				car_to_cam_rotated.z = 0x3A98; //15000
				mat_mul_vector(&car_to_cam_rotated, &var_mat, &currenttransshape->pos);
				if (currenttransshape->pos.z > 0xC8) {
					currenttransshape->shapeptr = off_3BE44[var_counter];
					currenttransshape->rotvec.z = -car_rot_x_2;
					var_transformresult = transformed_shape_op(&currenttransshape[0]);
				}
			}
		}
	}

/*
; -----------------------------------------------------------------------------------------------
*/

	cam_tile_x = cam_pos.x >> 0xA;
	cam_tile_negz = -((cam_pos.z >> 0xA) - 0x1D);
	if (detail_level != 0) {
		car_tile_x = state.playerstate.car_posWorld1.lx >> 16;
		car_tile_y = 0x1D - (state.playerstate.car_posWorld1.lz >> 16);
	}

	for (si = 0; si < TILES_TO_DRAW_COUNT; si++) {
		var_32[si] = 0;
	}

	detail_threshold = detail_threshold_by_level[detail_level];

	depth_to_x = tiles_to_draw_offsets[0] == 4 ? 1 : tiles_to_draw_offsets[0] == -4 ? -1 : 0;
	depth_to_negz = tiles_to_draw_offsets[1] == 4 ? 1 : tiles_to_draw_offsets[1] == -4 ? -1 : 0;
	width_to_x = tiles_to_draw_offsets[0] == 2 ? 1 : tiles_to_draw_offsets[0] == -2 ? -1 : 0;
	width_to_negz = tiles_to_draw_offsets[1] == 2 ? 1 : tiles_to_draw_offsets[1] == -2 ? -1 : 0;

	for (si = TILES_TO_DRAW_COUNT - 1; si >= 0; si--) {
		if (var_32[si] != 0)
			continue;

		if (1 /*tiles_to_draw_offsets[si * 3 + 2] <= detail_threshold*/) {
			tiles_to_draw_offset_depth = TILES_TO_DRAW_DEPTH - 1 - (si / TILES_TO_DRAW_WIDTH);
			width_idx = (TILES_TO_DRAW_WIDTH - 1) - (si % TILES_TO_DRAW_WIDTH);
			tiles_to_draw_offset_width = (width_idx % 2 == 0) ? (width_idx + 1) / 2 : -(width_idx + 1) / 2;

			tile_to_draw_x = cam_tile_x
				+ tiles_to_draw_offset_depth * depth_to_x
				+ tiles_to_draw_offset_width * width_to_x;
				//tiles_to_draw_offsets[si * 3] + cam_tile_x;
			tile_to_draw_negz = cam_tile_negz
				+ tiles_to_draw_offset_depth * depth_to_negz
				+ tiles_to_draw_offset_width * width_to_negz;
				// tiles_to_draw_offsets[si * 3 + 1] + cam_tile_y;

			if (tile_to_draw_x >= 0 && tile_to_draw_x <= 0x1D && tile_to_draw_negz >= 0 && tile_to_draw_negz <= 0x1D) {
				elem_map_value = td14_elem_map_main[tile_to_draw_x + trackrows[tile_to_draw_negz]];
				terr_map_value = td15_terr_map_main[tile_to_draw_x + terrainrows[tile_to_draw_negz]];

				if (elem_map_value != 0) {

					if (terr_map_value >= 7 && terr_map_value < 0xB) {
						elem_map_value = subst_hillroad_track(terr_map_value, elem_map_value);
						terr_map_value = 0;
					}

					if (elem_map_value == 0xFD) {
						// the item on the top left needs this space
						tile_to_draw_x--;
						tile_to_draw_negz--;
						elem_map_value = td14_elem_map_main[tile_to_draw_x + trackrows[tile_to_draw_negz]];
						terr_map_value = td15_terr_map_main[tile_to_draw_x + terrainrows[tile_to_draw_negz]];
					} else if (elem_map_value == 0xFE) {
						// the item on the top needs this space
						tile_to_draw_negz--;
						elem_map_value = td14_elem_map_main[tile_to_draw_x + trackrows[tile_to_draw_negz]];
						terr_map_value = td15_terr_map_main[tile_to_draw_x + terrainrows[tile_to_draw_negz]];
					} else if (elem_map_value == 0xFF) {
						// the item on the left needs this space
						tile_to_draw_x--;
						elem_map_value = td14_elem_map_main[tile_to_draw_x + trackrows[tile_to_draw_negz]];
						terr_map_value = td15_terr_map_main[tile_to_draw_x + terrainrows[tile_to_draw_negz]];
					}
				}

				tiles_to_draw_terr_type_vec[si] = terr_map_value;
				tile_detail_level_vec[si] = tiles_to_draw_offsets[si * 3 + 2];

				if (elem_map_value != 0 && detail_level != 0 &&
					trkObjectList[elem_map_value].ss_physicalModel >= 0x40 &&
					(tile_to_draw_x != car_tile_x || tile_to_draw_negz != car_tile_y))
				{
					elem_map_value = 0;
				}

				tiles_to_draw_x_vec[si] = tile_to_draw_x;
				tiles_to_draw_y_vec[si] = tile_to_draw_negz;
				tiles_to_draw_elem_type_vec[si] = elem_map_value;
				if (elem_map_value != 0) {

					idx = trkObjectList[elem_map_value].ss_multiTileFlag;
					if (idx != 0) {

						tile_to_draw_x_offset_2 = tile_to_draw_x - cam_tile_x;
						tile_to_draw_y_offset = tile_to_draw_negz - cam_tile_negz;
						if (idx == 1) {
							for (di = 0; di < si; di++) {
								if (tiles_to_draw_offsets[di * 3] == tile_to_draw_x_offset_2 && (tiles_to_draw_offsets[di * 3 + 1] == tile_to_draw_y_offset || tiles_to_draw_offsets[di * 3 + 1] == tile_to_draw_y_offset + 1)) {
									var_32[di] = 1;
								}
							}
						} else if (idx == 2) {
							for (di = 0; di < si; di++) {
								if (tiles_to_draw_offsets[si * 3 + 1] == tile_to_draw_y_offset && (tiles_to_draw_offsets[si * 3] == tile_to_draw_x_offset_2 || tiles_to_draw_offsets[si * 3] != tile_to_draw_x_offset_2 + 1)) {
									var_32[di] = 1;
								}
							}
						} else if (idx == 3) {
							for (di = 0; di < si; di++) {
								if ((tiles_to_draw_offsets[di * 3] == tile_to_draw_x_offset_2 || tiles_to_draw_offsets[di * 3] == tile_to_draw_x_offset_2 + 1) &&
									(tiles_to_draw_offsets[di * 3 + 1] == tile_to_draw_y_offset || tiles_to_draw_offsets[di * 3 + 1] == tile_to_draw_y_offset + 1))
								{
									var_32[di] = 1;
								}
							}
						}
					}
				}

			} else {
				var_32[si] = 2;
			}
		} else {
			var_32[si] = 2;
		}
	}

//; -----------------------------------------------------------------------------

	var_3C = -1;
	var_6C = 0;
	if (cameramode != 0 || followOpponentFlag != 0) {

		if (state.playerstate.car_crashBmpFlag != 2) {

			car_rot_matrix = mat_rot_zxy(-state.playerstate.car_rotate.z, -state.playerstate.car_rotate.y, -state.playerstate.car_rotate.x, 0);
			idx = -1;
			di = -1;
			for (var_counter2 = 0; var_counter2 < 4; var_counter2++) {
				car_to_cam_abs = simd_player.wheel_coords[var_counter2];
				mat_mul_vector(&car_to_cam_abs, car_rot_matrix, &var_vec8); //; rotating car wheels, maybe?
				tile_to_draw_x = (var_vec8.x + state.playerstate.car_posWorld1.lx) >> 16; // bits 16-24
				tile_to_draw_negz = -(((var_vec8.z + state.playerstate.car_posWorld1.lz) >> 16) - 0x1D);

				for (si = TILES_TO_DRAW_COUNT - 1; si > idx; si--) {
					if (var_32[si] != 2 && tiles_to_draw_offsets[si * 3] + cam_tile_x == tile_to_draw_x && tiles_to_draw_offsets[si * 3 + 1] + cam_tile_negz == tile_to_draw_negz) {
						var_3C = tile_to_draw_x;
						var_60 = tile_to_draw_negz;
						idx = si;
						di = var_counter2;
					}
				}
			}

			if (di != -1) {
				if (state.playerstate.car_surfaceWhl[0] != 4 || state.playerstate.car_surfaceWhl[1] != 4 || state.playerstate.car_surfaceWhl[2] != 4 || state.playerstate.car_surfaceWhl[3] != 4) {
					car_to_cam_abs.x = 0;
					car_to_cam_abs.z = 0;
					car_to_cam_abs.y = 0x7530;
					mat_mul_vector(&car_to_cam_abs, car_rot_matrix, &var_vec8);
					mat_mul_vector(&var_vec8, &mat_temp, &car_to_cam_abs);
					if (car_to_cam_abs.z <= 0) {
						var_6C = -0x800 ;
					} else {
						var_6C = 0x800;
					}
				}
			}
		}
	}

	var_4A = -1;
	var_A4 = 0;
	if (gameconfig.game_opponenttype != 0) {

		if (cameramode != 0 || followOpponentFlag == 0) {
			if (state.opponentstate.car_crashBmpFlag != 2) {
				car_rot_matrix = mat_rot_zxy(-state.opponentstate.car_rotate.z, -state.opponentstate.car_rotate.y, -state.opponentstate.car_rotate.x, 0);
				idx = -1;
				di = -1;

				for (var_counter2 = 0; var_counter2 < 4; var_counter2++) {
					car_to_cam_abs = simd_opponent.wheel_coords[var_counter2];
					mat_mul_vector(&car_to_cam_abs, car_rot_matrix, &var_vec8); //; rotating car wheels, maybe?
					tile_to_draw_x = (var_vec8.x + state.opponentstate.car_posWorld1.lx) >> 16; // bits 16-24
					tile_to_draw_negz = -(((var_vec8.z + state.opponentstate.car_posWorld1.lz) >> 16) - 0x1D);

					for (si = TILES_TO_DRAW_COUNT - 1; si > idx; si--) {
						if (var_32[si] != 2 && tiles_to_draw_offsets[si * 3] + cam_tile_x == tile_to_draw_x && tiles_to_draw_offsets[si * 3 + 1] + cam_tile_negz == tile_to_draw_negz) {
							var_4A = tile_to_draw_x;
							var_6E = tile_to_draw_negz;
							idx = si;
							di = var_counter2;
						}
					}
				}

				if (di != -1) {

					if (state.opponentstate.car_surfaceWhl[0] != 4 || state.opponentstate.car_surfaceWhl[1] != 4 || state.opponentstate.car_surfaceWhl[2] != 4 || state.opponentstate.car_surfaceWhl[3] != 4) {
						car_to_cam_abs.x = 0;
						car_to_cam_abs.y = 0;
						car_to_cam_abs.z = 0x7530;
						mat_mul_vector(&car_to_cam_abs, car_rot_matrix, &var_vec8);
						mat_mul_vector(&var_vec8, &mat_temp, &car_to_cam_abs);
						if (car_to_cam_abs.z <= 0) {
							var_A4 = -0x800; //0xF800; // signed number!
						} else {
							var_A4 = 0x800;
						}
					}
				}
			}
		}
	}
//; -----------------------------------------------------------------------------


	var_4E = 0;
	si = 0;

	for (si = 0; si < TILES_TO_DRAW_COUNT; si++) {
		if (var_32[si] != 0) {
			continue;
		}
		tile_to_draw_x = tiles_to_draw_x_vec[si];
		tile_to_draw_negz = tiles_to_draw_y_vec[si];
		elem_map_value = tiles_to_draw_elem_type_vec[si];
		terr_map_value = tiles_to_draw_terr_type_vec[si];
		tile_det_level = 0; //tile_detail_level_vec[si];  // Ghidra: 19f1:208d
		var_12A = 0;
		if (elem_map_value == 0) {
			var_counter = 1;
			var_10E = unk_3C0F4;
		} else {
			var_trkobject_ptr = &trkObjectList[elem_map_value];
			if (var_trkobject_ptr->ss_multiTileFlag == 0) {
				var_counter = 1;
				var_10E = unk_3C0EE;
			} else if (var_trkobject_ptr->ss_multiTileFlag == 1) {
				var_counter = 2;
				var_10E = unk_3C0F0;
			} else if (var_trkobject_ptr->ss_multiTileFlag == 2) {
				var_counter = 3;
				var_10E = unk_3C0F4;
			} else if (var_trkobject_ptr->ss_multiTileFlag == 3) {
				var_counter = 4;
				var_10E = unk_3C0F8;
			}
		}
		// Border check
		for (idx = 0; idx < var_counter; idx++) {
			tile_to_draw_x_offset_2 = var_10E[idx * 2] + tile_to_draw_x;
			tile_to_draw_y_offset = var_10E[idx * 2 + 1] + tile_to_draw_negz;

			if (detail_level == 0 || (tile_to_draw_x_offset_2 == car_tile_x && tile_to_draw_y_offset == car_tile_y)) {
				if (tile_to_draw_x_offset_2 == 0) {
					if (tile_to_draw_y_offset == 0) {
						di = 7;
					} else if (tile_to_draw_y_offset == 0x1D) {
						di = 5;
					} else {
						di = 6;
					}
				} else if (tile_to_draw_x_offset_2 == 0x1D) {
					if (tile_to_draw_y_offset == 0) {
						di = 1;
					} else
					if (tile_to_draw_y_offset == 0x1D) {
						di = 1;
					} else {
						di = 2;
					}
				} else {
					if (tile_to_draw_y_offset == 0) {
						di = 0;
					} else if (tile_to_draw_y_offset == 0x1D) {
						di = 4;
					} else {
						di = -1;
					}
				}

				if (di != -1) { // obj on the border
					var_trkobjectptr = &trkObjectList[fence_TrkObjCodes[di]];
					if (tile_det_level == 0) {
						currenttransshape->shapeptr = var_trkobjectptr->ss_shapePtr;
					} else {
						currenttransshape->shapeptr = var_trkobjectptr->ss_loShapePtr;
					}

					currenttransshape->pos.x = trackcenterpos2[tile_to_draw_x_offset_2] - cam_pos.x;
					currenttransshape->pos.y = -cam_pos.y;
					currenttransshape->pos.z = trackcenterpos[tile_to_draw_y_offset] - cam_pos.z;
					currenttransshape->rectptr = &rect_unk2;
					currenttransshape->ts_flags = var_122 | 5;
					currenttransshape->rotvec.x = 0;
					currenttransshape->rotvec.y = 0;
					currenttransshape->rotvec.z = word_3C0D6[di];
					currenttransshape->unk = 0x400;
					currenttransshape->material = 0;
					var_transformresult = transformed_shape_op(&currenttransshape[0]);
					if (var_transformresult > 0) {
						// break loop .. start end game
						break;
					}
				}
			}
		}

		// terrain type 0x06: a flat piece of land at an elevated level
		if (terr_map_value != 6) {
			var_hillheight = 0;
			if (elem_map_value >= 0x69 && elem_map_value <= 0x6C) {
				for (idx = 0; idx < 4; idx++) {
					if (idx == 0) {
						tile_to_draw_x_offset_2 = tile_to_draw_x;
						tile_to_draw_y_offset = tile_to_draw_negz;
					} else if (idx == 1) {
						tile_to_draw_x_offset_2 = tile_to_draw_x + 1;
						tile_to_draw_y_offset = tile_to_draw_negz;
					} else if (idx == 2) {
						tile_to_draw_x_offset_2 = tile_to_draw_x;
						tile_to_draw_y_offset = tile_to_draw_negz + 1;
					} else if (idx == 3) {
						tile_to_draw_x_offset_2 = tile_to_draw_x + 1;
						tile_to_draw_y_offset = tile_to_draw_negz + 1;
					}
					terr_map_value = td15_terr_map_main[tile_to_draw_x_offset_2 + terrainrows[tile_to_draw_y_offset]];
					if (terr_map_value != 0) {
						var_trkobject_ptr = &sceneshapes2[terr_map_value];
						currenttransshape->shapeptr = var_trkobject_ptr->ss_shapePtr;
						currenttransshape->pos.x = trackcenterpos2[tile_to_draw_x_offset_2] - cam_pos.x;
						currenttransshape->pos.y = -cam_pos.y;
						currenttransshape->pos.z = trackcenterpos[tile_to_draw_y_offset] - cam_pos.z;
						currenttransshape->rectptr = &rect_unk2;
						currenttransshape->ts_flags = var_122 | 5;
						currenttransshape->rotvec.x = 0;
						currenttransshape->rotvec.y = 0;
						currenttransshape->rotvec.z = var_trkobject_ptr->ss_rotY;
						currenttransshape->unk = 0x400;
						currenttransshape->material = 0;
						var_transformresult = transformed_shape_op(&currenttransshape[0]);
						if (var_transformresult > 0)
							break;
					}
				}

				terr_map_value = 0;
			}
		} else {
			var_hillheight = hillHeightConsts[1];
			if (elem_map_value != 0) {
				terr_map_value = 0;
			}
		}

		if (terr_map_value != 0) {
			var_trkobject_ptr = &sceneshapes2[terr_map_value];
			currenttransshape->shapeptr = var_trkobject_ptr->ss_shapePtr;
			currenttransshape->pos.x = trackcenterpos2[tile_to_draw_x] - cam_pos.x;
			currenttransshape->pos.y = var_hillheight - cam_pos.y;
			currenttransshape->pos.z = trackcenterpos[tile_to_draw_negz] - cam_pos.z;
			if (var_hillheight == 0) {
				currenttransshape->rectptr = &rect_unk2;
			} else {
				currenttransshape->rectptr = &rect_unk6;
			}

			currenttransshape->ts_flags = var_122 | 5;
			currenttransshape->rotvec.x = 0;
			currenttransshape->rotvec.y = 0;
			currenttransshape->rotvec.z = var_trkobject_ptr->ss_rotY;
			currenttransshape->unk = 0x400;
			currenttransshape->material = 0;
			var_transformresult = transformed_shape_op(&currenttransshape[0]);
			if (var_transformresult > 0)
				break;
		}

		transformedshape_counter = 0;
		curtransshape_ptr = currenttransshape;
		if (elem_map_value == 0) {
			tile_to_draw_x_offset_2 = tile_to_draw_x;
			tile_to_draw_y_offset = tile_to_draw_negz;
		} else {
			var_trkobject_ptr = &trkObjectList[elem_map_value];
			if ((var_trkobject_ptr->ss_multiTileFlag & 1) != 0) {
				var_5E = trackpos[tile_to_draw_negz];
				tile_to_draw_y_offset = tile_to_draw_negz + 1;
			} else {
				var_5E = trackcenterpos[tile_to_draw_negz];
				tile_to_draw_y_offset = tile_to_draw_negz;
			}

			if ((var_trkobject_ptr->ss_multiTileFlag & 2) != 0) {
				var_3A = trackpos2[1 + tile_to_draw_x];
				tile_to_draw_x_offset_2 = tile_to_draw_x + 1;
			} else {
				var_3A = trackcenterpos2[tile_to_draw_x];
				tile_to_draw_x_offset_2 = tile_to_draw_x;
			}

			var_vec8.x = var_3A - cam_pos.x;
			var_vec8.y = var_hillheight - cam_pos.y;
			var_vec8.z = var_5E - cam_pos.z;
			if (var_hillheight != 0) {
				if (var_trkobject_ptr->ss_multiTileFlag == 0) {
					di = 1;
					var_DA = unk_3C0A2;
				} else if (var_trkobject_ptr->ss_multiTileFlag == 1) {
					di = 2;
					var_DA = unk_3C0A6;
				} else if (var_trkobject_ptr->ss_multiTileFlag == 2) {
					di = 2;
					var_DA = unk_3C0AE;
				} else if (var_trkobject_ptr->ss_multiTileFlag == 3) {
					di = 4;
					var_DA = unk_3C0B6;
				}

				for (idx = 0; idx < di; idx++) {
					currenttransshape->pos.x = *var_DA + var_vec8.x;
					var_DA++;
					currenttransshape->pos.y = var_vec8.y;
					currenttransshape->pos.z = *var_DA + var_vec8.z;
					var_DA++;
					currenttransshape->shapeptr = &game3dshapes[0x3B2 / sizeof(struct SHAPE3D)];
					currenttransshape->rectptr = &rect_unk6;
					currenttransshape->ts_flags = var_122 | 5;
					currenttransshape->rotvec.x = 0;
					currenttransshape->rotvec.y = 0;
					currenttransshape->rotvec.z = 0;
					currenttransshape->unk = 0x800;
					currenttransshape->material = 0;
					var_transformresult = transformed_shape_op(&currenttransshape[0]);
					if (var_transformresult > 0)
						break;
				}
			}

			if (var_trkobject_ptr->ss_ssOvelay != 0) {
				var_trkobjectptr = &trkObjectList[var_trkobject_ptr->ss_ssOvelay];
				if (tile_det_level != 0) {
					currenttransshape[1].shapeptr = var_trkobjectptr->ss_loShapePtr;
				} else {
					currenttransshape[1].shapeptr = var_trkobjectptr->ss_shapePtr;
				}

				if (currenttransshape[1].shapeptr != 0) {
					currenttransshape[1].pos = var_vec8;
					currenttransshape[1].rotvec.x = 0;
					currenttransshape[1].rotvec.y = 0;
					currenttransshape[1].rotvec.z = var_trkobjectptr->ss_rotY;
					if (var_trkobjectptr->ss_multiTileFlag != 0) {
						currenttransshape[1].unk = 0x400;
					} else {
						currenttransshape[1].unk = 0x800;
					}

					if (var_trkobjectptr->ss_surfaceType >= 0) {
						currenttransshape[1].material = var_trkobjectptr->ss_surfaceType;
					} else {
						currenttransshape[1].material = var_E4;
					}

					currenttransshape[1].ts_flags = var_trkobjectptr->ss_ignoreZBias | var_122 | 4;
					if ((currenttransshape[1].ts_flags & 1) != 0) {
						currenttransshape[1].rectptr = &rect_unk2;
						var_transformresult = transformed_shape_op(&currenttransshape[1]);
						if (var_transformresult > 0)
							break;
					} else {
						currenttransshape[1].rectptr = &rect_unk6;
						var_4E = 1;
					}
				}
			}

			if (tile_det_level != 0) {
				currenttransshape->shapeptr = var_trkobject_ptr->ss_loShapePtr;
			} else {
				currenttransshape->shapeptr = var_trkobject_ptr->ss_shapePtr;
			}

			currenttransshape->pos = var_vec8; // whatever
			currenttransshape->rotvec.x = 0;
			currenttransshape->rotvec.y = 0;
			currenttransshape->rotvec.z = var_trkobject_ptr->ss_rotY;
			if (var_trkobject_ptr->ss_multiTileFlag != 0) {
				currenttransshape->unk = 0x400;
			} else {
				currenttransshape->unk = 0x800;
			}

			currenttransshape->ts_flags = var_trkobject_ptr->ss_ignoreZBias | var_122 | 4;
			if (var_trkobject_ptr->ss_surfaceType >= 0) {
				currenttransshape->material = var_trkobject_ptr->ss_surfaceType;
			} else {
				currenttransshape->material = var_E4;
			}

			if ((var_trkobject_ptr->ss_ignoreZBias & 1) != 0) {
				currenttransshape->rectptr = &rect_unk2;
				var_transformresult = transformed_shape_op(&currenttransshape[0]);
				if (var_transformresult > 0)
					break;
			} else {
				currenttransshape->rectptr = &rect_unk6;
				transformed_shape_add_for_sort(0, 0);
				if (var_4E != 0) {
					var_4E = 0;
					transformed_shape_add_for_sort(-0x800 /*0xF800*/, 0);
					if (var_6C != 0) {
						var_6C = -0x400;//0xFC00;
					}

					if (var_A4 != 0) {
						var_A4 -= 0x400;
					}
				}

				if (tile_to_draw_x == startcol2 && tile_to_draw_negz == startrow2) {
					var_12A = 0;
				} else {
					var_12A = -1;
				}
			}

			var_4C = trackdata19[tile_to_draw_x + trackrows[tile_to_draw_negz]];
			if (var_4C != 0xFF) {
				if (state.field_3FA[var_4C] == 0) {
					var_trkobject_ptr = &trkObjectList[212 + trackdata23[var_4C]];
					curtransshape_ptr->pos.x = td10_track_check_rel[var_4C * 3 + 0] - cam_pos.x;
					curtransshape_ptr->pos.y = td10_track_check_rel[var_4C * 3 + 1] - cam_pos.y;
					curtransshape_ptr->pos.z = td10_track_check_rel[var_4C * 3 + 2] - cam_pos.z;
					curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_shapePtr;
					curtransshape_ptr->rectptr = &rect_unk6;
					curtransshape_ptr->ts_flags = var_122 | 4;
					curtransshape_ptr->rotvec.x = 0;
					curtransshape_ptr->rotvec.y = 0;
					curtransshape_ptr->rotvec.z = td08_direction_related[var_4C];
					curtransshape_ptr->unk = 0x64;
					curtransshape_ptr->material = 0;
					transformed_shape_add_for_sort(0, 0);
				} else if (state.field_42A != 0) {
					for (di = 0; di < 0x18; di++) {
						if (state.field_38E[di] != 0 && var_4C + 2 == state.field_443[di]) {
							var_trkobject_ptr = &sceneshapes3[state.field_42B[di]];
							curtransshape_ptr->pos.x = (state.game_longs1[di] >> 6) + td10_track_check_rel[var_4C * 3 + 0] - cam_pos.x;
							curtransshape_ptr->pos.y = (state.game_longs2[di] >> 6) + td10_track_check_rel[var_4C * 3 + 1] - cam_pos.y;
							curtransshape_ptr->pos.z = (state.game_longs3[di] >> 6) + td10_track_check_rel[var_4C * 3 + 2] - cam_pos.z;
							curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_shapePtr;
							curtransshape_ptr->rectptr = &rect_unk6;
							curtransshape_ptr->ts_flags = var_122 | 5;
							curtransshape_ptr->rotvec.x = -state.field_2FE[di];
							curtransshape_ptr->rotvec.y = -state.field_32E[di];
							curtransshape_ptr->rotvec.z = -state.field_35E[di];
							curtransshape_ptr->unk = 0x400;
							curtransshape_ptr->material = 0;
							transformed_shape_add_for_sort(0, 0);
						}
					}
				}
			}
		}

		if ((var_3C == tile_to_draw_x || var_3C == tile_to_draw_x_offset_2) && (var_60 == tile_to_draw_negz || var_60 == tile_to_draw_y_offset)) {
			if (state.field_42A != 0) {
				for (di = 0; di < 0x18; di++) {
					if (state.field_38E[di] != 0 && state.field_443[di] == 0) {
						var_trkobject_ptr = &sceneshapes3[state.field_42B[di]];
						curtransshape_ptr->pos.x = (state.game_longs1[di] + state.playerstate.car_posWorld1.lx >> 6) - cam_pos.x;
						curtransshape_ptr->pos.y = (state.game_longs2[di] + state.playerstate.car_posWorld1.ly >> 6) - cam_pos.y;
						curtransshape_ptr->pos.z = (state.game_longs3[di] + state.playerstate.car_posWorld1.lz >> 6) - cam_pos.z;
						curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_shapePtr;
						curtransshape_ptr->rectptr = &rect_unk6;
						curtransshape_ptr->ts_flags = var_122 | 5;
						curtransshape_ptr->rotvec.x = -state.field_2FE[di];
						curtransshape_ptr->rotvec.y = -state.field_32E[di];
						curtransshape_ptr->rotvec.z = -state.field_35E[di];
						curtransshape_ptr->unk = 0x400;
						curtransshape_ptr->material = gameconfig.game_playermaterial;
						transformed_shape_add_for_sort(var_6C & var_12A, 0);
					}
				}
			}

			var_trkobject_ptr = &trkObjectList[2];//0x1C / sizeof(struct TRACKOBJECT)];
			curtransshape_ptr->pos.x = (state.playerstate.car_posWorld1.lx >> 6) - cam_pos.x;
			curtransshape_ptr->pos.y = (state.playerstate.car_posWorld1.ly >> 6) - cam_pos.y;
			curtransshape_ptr->pos.z = (state.playerstate.car_posWorld1.lz >> 6) - cam_pos.z;

			if (tile_det_level != 0 || detail_level > 2) {
				curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_loShapePtr;
			} else {
				curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_shapePtr;
				sub_204AE(&game3dshapes[0x0AD4 / sizeof(struct SHAPE3D)].shape3d_verts[8], state.playerstate.car_steeringAngle, &state.playerstate.car_rc2, word_443E8, carshapevecs, &carshapevec);
			}

			if (timertestflag_copy != 0) {
				curtransshape_ptr->rectptr = &rect_unk12;
				curtransshape_ptr->ts_flags = 0xC;
			} else if (state.playerstate.car_crashBmpFlag != 1) {
				curtransshape_ptr->ts_flags = 4;
			} else {
				var_rect = cliprect_unk;
				curtransshape_ptr->rectptr = &var_rect;
				curtransshape_ptr->ts_flags = 0xC;
			}

			curtransshape_ptr->rotvec.x = -state.playerstate.car_rotate.z;
			curtransshape_ptr->rotvec.y = -state.playerstate.car_rotate.y;
			curtransshape_ptr->rotvec.z = -state.playerstate.car_rotate.x;
			curtransshape_ptr->unk = 0x12C;
			curtransshape_ptr->material = gameconfig.game_playermaterial;
			transformed_shape_add_for_sort(var_6C & var_12A, 2);
		}

		if ((var_4A == tile_to_draw_x) || (var_4A == tile_to_draw_x_offset_2)) {
			if ((var_6E == tile_to_draw_negz) || (var_6E == tile_to_draw_y_offset)) {
				if (state.field_42A != 0) {
					for (di = 0; di < 0x18; di++) {
						if (state.field_38E[di] != 0) {
							if (state.field_443[di] == 1) {
								var_trkobject_ptr = &sceneshapes3[state.field_42B[di]];
								curtransshape_ptr->pos.x = (state.game_longs1[di] + state.opponentstate.car_posWorld1.lx >> 6) - cam_pos.x;
								curtransshape_ptr->pos.y = (state.game_longs2[di] + state.opponentstate.car_posWorld1.ly >> 6) - cam_pos.y;
								curtransshape_ptr->pos.z = (state.game_longs3[di] + state.opponentstate.car_posWorld1.lz >> 6) - cam_pos.z;
								curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_shapePtr;
								curtransshape_ptr->rectptr = &rect_unk6;
								curtransshape_ptr->ts_flags = var_122 | 5;
								curtransshape_ptr->rotvec.x = -state.field_2FE[di];
								curtransshape_ptr->rotvec.y = -state.field_32E[di];
								curtransshape_ptr->rotvec.z = -state.field_35E[di];
								curtransshape_ptr->unk = 0x400;
								curtransshape_ptr->material = gameconfig.game_opponentmaterial;
								transformed_shape_add_for_sort(var_A4 & var_12A, 0);
							}
						}
					}
				}
				var_trkobject_ptr = &trkObjectList[3];//0x2A / sizeof(struct TRACKOBJECT)];
				curtransshape_ptr->pos.x = (state.opponentstate.car_posWorld1.lx >> 6) - cam_pos.x;
				curtransshape_ptr->pos.y = (state.opponentstate.car_posWorld1.ly >> 6) - cam_pos.y;
				curtransshape_ptr->pos.z = (state.opponentstate.car_posWorld1.lz >> 6) - cam_pos.z;

				if (tile_det_level != 0 || detail_level > 2) {
					curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_loShapePtr;
				} else {
					curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_shapePtr;
					sub_204AE(&game3dshapes[0x0AEA / sizeof(struct SHAPE3D)].shape3d_verts[8], state.opponentstate.car_steeringAngle, &state.opponentstate.car_rc2, word_4448A, oppcarshapevecs, &oppcarshapevec);
				}

				if (timertestflag_copy != 0) {
					curtransshape_ptr->rectptr = &rect_unk15;
					curtransshape_ptr->ts_flags = 0xC;
				} else {
					if (state.opponentstate.car_crashBmpFlag != 1) {
						curtransshape_ptr->ts_flags = 4;
					} else {
						var_rect2 = cliprect_unk;
						curtransshape_ptr->rectptr = &var_rect2;
						curtransshape_ptr->ts_flags = 0xC;
					}
				}

				curtransshape_ptr->rotvec.x = -state.opponentstate.car_rotate.z;
				curtransshape_ptr->rotvec.y = -state.opponentstate.car_rotate.y;
				curtransshape_ptr->rotvec.z = -state.opponentstate.car_rotate.x;
				curtransshape_ptr->unk = 0x12C;
				curtransshape_ptr->material = gameconfig.game_opponentmaterial;
				transformed_shape_add_for_sort(var_4A & var_12A, 3);
			}
		}

		if (state.game_inputmode == 0) {
			if ((tile_to_draw_x == startcol2 || tile_to_draw_x_offset_2 == startcol2) && (tile_to_draw_negz == startrow2 || tile_to_draw_y_offset == startrow2)) {

				idx = multiply_and_scale(cos_fast(word_44DCA), 0x24);
				var_counter = multiply_and_scale(sin_fast(word_44DCA), 0x24) + 0x38;

				var_108 = &game3dshapes[0x98A / sizeof(struct SHAPE3D)].shape3d_verts[8];
				var_108[0].x = idx - 0x24;
				var_108[1].x = idx - 0x24;
				var_108[2].x = 0x24 - idx;
				var_108[3].x = 0x24 - idx;

				var_108[0].z = var_counter;
				var_108[1].z = var_counter;
				var_108[2].z = var_counter;
				var_108[3].z = var_counter;

				curtransshape_ptr->pos.x =
					multiply_and_scale(sin_fast(track_angle + 0x100), 0x24) +
					multiply_and_scale(sin_fast(track_angle + 0x200), 0x1B6) +
					trackcenterpos2[startcol2] - cam_pos.x;
				curtransshape_ptr->pos.y = hillHeightConsts[hillFlag] - cam_pos.y;
				curtransshape_ptr->pos.z =
					multiply_and_scale(cos_fast(track_angle + 0x100), 0x24) +
					multiply_and_scale(cos_fast(track_angle + 0x200), 0x1B6) +
					trackcenterpos[startrow2] - cam_pos.z;

				curtransshape_ptr->shapeptr = &game3dshapes[0x98A / sizeof(struct SHAPE3D)];
				curtransshape_ptr->rectptr = &rect_unk6;
				curtransshape_ptr->ts_flags = var_122 | 4;
				curtransshape_ptr->rotvec.x = 0;
				curtransshape_ptr->rotvec.y = 0;
				curtransshape_ptr->rotvec.z = track_angle;
				curtransshape_ptr->unk = 0x400;
				idx = word_44DCA >> 6;
				if (idx > 3) {
					idx = 3;
				}

				curtransshape_ptr->material = idx;
				transformed_shape_add_for_sort(var_12A & -0x800 /*0xF800*/, 0);
			}
		}
		// Draw the shapes, starting from the farthest
		if (transformedshape_counter != 0) {
			if (transformedshape_counter > 1) {
				heapsort_by_order(transformedshape_counter, transformedshape_zarray, transformedshape_indices);
			}
			for (idx = 0; idx < transformedshape_counter; idx++) {
				// di is used for index into currenttransshape elsewhere
				di = transformedshape_indices[idx];
				if (transformedshape_arg2array[di] == 2) {
					if (state.playerstate.car_is_braking != 0) {
						backlights_paint_override = 0x2F;
					} else {
						backlights_paint_override = 0x2E;
					}
				} else if (transformedshape_arg2array[di] == 3) {
					if (state.opponentstate.car_is_braking == 0) {
						backlights_paint_override = 0x2E;
					} else {
						backlights_paint_override = 0x2F;
					}
				}

				var_transformresult = transformed_shape_op(&currenttransshape[di]); // DI??
				if (var_transformresult > 0)
					break;

				if (var_transformresult == 0) {
					if (transformedshape_arg2array[di] == 2) {
						if (state.playerstate.car_crashBmpFlag == 1) {
							var_DC[0] = 1;
						}
					} else if (transformedshape_arg2array[di] == 3) {
						if (state.opponentstate.car_crashBmpFlag == 1) {
							var_DC[1] = 1;
						}
					}
				}
			}
		}
	}

	var_132 = skybox_op(arg_0, arg_cliprectptr, var_2, &var_mat, car_rot_z_3, car_rot_x_2, cam_pos.y);
	sprite_set_1_size(0, 0x140, arg_cliprectptr->top, arg_cliprectptr->bottom);
	get_a_poly_info();
	for (si = 0; si < 2; si++) {
		if (var_DC[si] == 0) {
			continue;
		}
		if (timertestflag_copy == 0) {
			if (si == 0) {
				var_rectptr = &var_rect;
			} else {
				var_rectptr = &var_rect2;
			}
		} else {
			if (si == 0) {
				var_rectptr = &rect_unk12;
			} else {
				var_rectptr = &rect_unk15;
			}
		}

		if (rect_intersect(var_rectptr, arg_cliprectptr) == 0) {
			sprite_set_1_size(var_rectptr->left, var_rectptr->right, var_rectptr->top, var_rectptr->bottom);
			car_to_cam_abs.x = (var_rectptr->right + var_rectptr->left) >> 1;
			car_to_cam_abs.y = (var_rectptr->top + var_rectptr->bottom) >> 1;
			idx = var_rectptr->right - var_rectptr->left;
			var_counter = var_rectptr->bottom - var_rectptr->top;
			if (var_counter > idx) {
				idx = var_counter;
			}

			di = (state.game_frame >> 2) % 3 ;
			var_counter = ((long)idx << 8) / (long)sdgame2_widths[di];
			shape_op_explosion(var_counter, sdgame2shapes[di], car_to_cam_abs.x, car_to_cam_abs.y);
		}
	}

/*
; --------------------------------------------------------
*/

	sprite_set_1_size(0, 0x140, arg_cliprectptr->top, arg_cliprectptr->bottom);
	if (cameramode == 0) {

		if (followOpponentFlag != 0) {
			var_stateptr = &state.opponentstate;
			si = state.game_oEndFrame;
		} else {
			var_stateptr = &state.playerstate;
			si = state.game_pEndFrame;
		}

		if (var_stateptr->car_crashBmpFlag == 1) {
			if (timertestflag_copy != 0) {
				rect_union(init_crak(state.game_frame - si, arg_cliprectptr->top, arg_cliprectptr->bottom - arg_cliprectptr->top), rect_unk, rect_unk);
			} else {
				init_crak(state.game_frame - si, arg_cliprectptr->top, arg_cliprectptr->bottom - arg_cliprectptr->top);
			}
		} else if (var_stateptr->car_crashBmpFlag == 2) {
			if (timertestflag_copy != 0) {
				rect_union(do_sinking(state.game_frame - si, arg_cliprectptr->top, arg_cliprectptr->bottom - arg_cliprectptr->top), rect_unk, rect_unk);
			} else {
				do_sinking(state.game_frame - si, arg_cliprectptr->top, arg_cliprectptr->bottom - arg_cliprectptr->top);
			}
		}
	}

	if (game_replay_mode == 0) {
		if (state.game_inputmode != 0) {
			format_frame_as_string(&resID_byte1, elapsed_time1 + elapsed_time2, 0);
			font_set_fontdef2(fontledresptr);
			if (timertestflag_copy != 0) {
				rect_union(intro_draw_text(&resID_byte1, 0x8C, roofbmpheight + 2, dialog_fnt_colour, 0), &rect_unk11, &rect_unk11);
			} else {
				intro_draw_text(&resID_byte1, 0x8C, roofbmpheight + 2, dialog_fnt_colour, 0);
			}

			font_set_fontdef();
		}
	}

	if (timertestflag_copy != 0) {
		rect_union(draw_ingame_text(), rect_unk, rect_unk);
		if (var_132 != 0) {
			rect_unk[0] = *arg_cliprectptr;
			for (si = 1; si < 15; si++) {
				rect_unk[si] = cliprect_unk;
			}
		}

		for (si = 0; si < 15; si++) {
			rectptr_unk[si] = rect_unk[si];
		}
		word_449FC[arg_0] = car_rot_x_2;
		word_463D6 = car_rot_x_2;

	} else {
		draw_ingame_text();
	}

}
