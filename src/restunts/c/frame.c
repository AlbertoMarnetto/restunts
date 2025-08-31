#include "externs.h"
#include "math.h"

// At rendering attempt x, only the tiles having a low_detail_priority lower
// than the x-th element of this array will be rendered in high detail
char low_detail_priority_thresholds_0[] = { 99, 20, 18, 16, 14, 12, 10 };
char low_detail_priority_thresholds_1[] = { 99, 10, 10, 10, 10, 10, 10 };
char low_detail_priority_thresholds_2[] = { 10, 10, 10, 10, 10, 10, 10 };
#define LOW_DETAIL_PRIORITY_THRESHOLDS_SIZE (sizeof(low_detail_priority_thresholds) / sizeof(*low_detail_priority_thresholds))

unsigned char tiles_to_draw_max[] = {180, 110, 80, 50, 1};
//unsigned char tiles_to_draw_max[] = {90, 90, 90, 90, 90};

struct TILE_REL_COORDS {
	char width;
	char depth;
	// A metric representing how acceptable it is to use the low-polygon
	// version of the models in this square in case the program needs to reduce the
	// memory consumption
	unsigned char low_detail_priority;
};

struct TILE_REL_COORDS lookahead_tiles_db[] = {
{   1,  13,  29 },
{  -1,  13,  29 },
{   0,  13,  26 },
{   8,   4,  32 },
{  -8,   4,  32 },
{   6,   9,  36 },
{  -6,   9,  36 },
{   7,   7,  35 },
{  -7,   7,  35 },
{   3,  12,  33 },
{  -3,  12,  33 },
{   5,  10,  35 },
{  -5,  10,  35 },
{   8,   3,  30 },
{  -8,   3,  30 },
{   4,  11,  34 },
{  -4,  11,  34 },
{   8,   2,  28 },
{  -8,   2,  28 },
{   2,  12,  30 },
{  -2,  12,  30 },
{   7,   6,  33 },
{  -7,   6,  33 },
{   6,   8,  34 },
{  -6,   8,  34 },
{   1,  12,  27 },
{  -1,  12,  27 },
{   0,  12,  24 },
{   3,  11,  31 },
{  -3,  11,  31 },
{   7,   5,  31 },
{  -7,   5,  31 },
{   5,   9,  33 },
{  -5,   9,  33 },
{   4,  10,  32 },
{  -4,  10,  32 },
{   6,   7,  32 },
{  -6,   7,  32 },
{   7,   4,  29 },
{  -7,   4,  29 },
{   2,  11,  28 },
{  -2,  11,  28 },
{   7,   3,  27 },
{  -7,   3,  27 },
{   5,   8,  31 },
{  -5,   8,  31 },
{   1,  11,  25 },
{  -1,  11,  25 },
{   3,  10,  29 },
{  -3,  10,  29 },
{   6,   6,  30 },
{  -6,   6,  30 },
{   0,  11,  22 },
{   4,   9,  30 },
{  -4,   9,  30 },
{   7,   2,  25 },
{  -7,   2,  25 },
{   6,   5,  28 },
{  -6,   5,  28 },
{   2,  10,  26 },
{  -2,  10,  26 },
{   5,   7,  29 },
{  -5,   7,  29 },
{   3,   9,  27 },
{  -3,   9,  27 },
{   1,  10,  23 },
{  -1,  10,  23 },
{   4,   8,  28 },
{  -4,   8,  28 },
{   6,   4,  26 },
{  -6,   4,  26 },
{   0,  10,  20 },
{   5,   6,  27 },
{  -5,   6,  27 },
{   6,   3,  24 },
{  -6,   3,  24 },
{   2,   9,  24 },
{  -2,   9,  24 },
{   6,   2,  22 },
{  -6,   2,  22 },
{   4,   7,  26 },
{  -4,   7,  26 },
{   3,   8,  25 },
{  -3,   8,  25 },
{   5,   5,  25 },
{  -5,   5,  25 },
{   1,   9,  21 },
{  -1,   9,  21 },
{   6,   1,  20 },
{  -6,   1,  20 },
{   0,   9,  18 },
{   5,   4,  23 },
{  -5,   4,  23 },
{   4,   6,  24 },
{  -4,   6,  24 },
{   2,   8,  22 },
{  -2,   8,  22 },
{   3,   7,  23 },
{  -3,   7,  23 },
{   5,   3,  21 },
{  -5,   3,  21 },
{   1,   8,  19 },
{  -1,   8,  19 },
{   0,   8,  16 },
{   4,   5,  22 },
{  -4,   5,  22 },
{   5,   2,  19 },
{  -5,   2,  19 },
{   2,   7,  20 },
{  -2,   7,  20 },
{   5,   1,  17 },
{  -5,   1,  17 },
{   3,   6,  21 },
{  -3,   6,  21 },
{   4,   4,  20 },
{  -4,   4,  20 },
{   1,   7,  17 },
{  -1,   7,  17 },
{   0,   7,  14 },
{   3,   5,  19 },
{  -3,   5,  19 },
{   4,   3,  18 },
{  -4,   3,  18 },
{   2,   6,  18 },
{  -2,   6,  18 },
{   4,   2,  16 },
{  -4,   2,  16 },
{   1,   6,  15 },
{  -1,   6,  15 },
{   3,   4,  17 },
{  -3,   4,  17 },
{   4,   1,  14 },
{  -4,   1,  14 },
{   0,   6,  12 },
{   4,   0,  12 },
{  -4,   0,  12 },
{   2,   5,  16 },
{  -2,   5,  16 },
{   3,   3,  15 },
{  -3,   3,  15 },
{   1,   5,  13 },
{  -1,   5,  13 },
{   2,   4,  14 },
{  -2,   4,  14 },
{   0,   5,  10 },
{   3,   2,  13 },
{  -3,   2,  13 },
{   3,   1,  11 },
{  -3,   1,  11 },
{   3,   0,   9 },
{  -3,   0,   9 },
{   1,   4,  11 },
{  -1,   4,  11 },
{   2,   3,  12 },
{  -2,   3,  12 },
{   0,   4,   8 },
{   2,   2,  10 },
{  -2,   2,  10 },
{   1,   3,   9 },
{  -1,   3,   9 },
{   2,   1,   8 },
{  -2,   1,   8 },
{   0,   3,   6 },
{   2,  -1,   8 },
{  -2,  -1,   8 },
{   2,   0,   6 },
{  -2,   0,   6 },
{   1,   2,   7 },
{  -1,   2,   7 },
{   0,   2,   4 },
{   1,   1,   5 },
{  -1,   1,   5 },
{   1,  -1,   5 },
{  -1,  -1,   5 },
{   1,   0,   3 },
{  -1,   0,   3 },
{   0,  -2,   4 },
{   0,   1,   2 },
{   0,  -1,   2 },
{   0,   0,   0 }
};
#define LOOKAHEAD_TILES_DB_SIZE (sizeof(lookahead_tiles_db) / sizeof(*lookahead_tiles_db))


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
extern int word_44D20;
extern char detail_threshold_by_level[];
extern char byte_3C0C6[];
extern char word_46468;
extern int word_3BE34[];
extern char* lookahead_tiles_tables[];
extern struct SHAPE3D* off_3BE44[];
extern int terrainHeight;
extern int planindex;
extern int planindex_copy;
extern char byte_4392C;
extern struct TRANSFORMEDSHAPE3D currenttransshape[29];
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
extern int transformedshape_zarray[29];
extern int transformedshape_indices[29];
extern char transformedshape_arg2array[29];
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

char get_low_detail_threshold_at_attempt(char attempt)
{
    char const * low_detail_priority_thresholds
        = graphic_level == 0 ? low_detail_priority_thresholds_0
        : graphic_level <= 2 ? low_detail_priority_thresholds_1
        :                     low_detail_priority_thresholds_2;

	if (attempt >= LOW_DETAIL_PRIORITY_THRESHOLDS_SIZE) {
		attempt = LOW_DETAIL_PRIORITY_THRESHOLDS_SIZE - 1;
	}
	return low_detail_priority_thresholds[attempt];
}

void update_frame(char arg_0, struct RECTANGLE* arg_cliprectptr) {
	int si;
	char var_122;
	char var_E4;
	char var_DC[2];
	struct RECTANGLE* var_rectptr;
	struct MATRIX var_mat, var_mat2;
	struct MATRIX* car_rot_matrix;
	struct VECTOR cam_pos, car_pos, offset_vector, car_to_cam_rotated, var_vec8;
	int car_rot_y, car_rot_x, car_rot_z;
	int car_rot_y_2, car_rot_x_2, car_rot_z_2;
	int var_38, car_rot_z_3;
	int var_transformresult;
	int heading;
	char* lookahead_tiles;
	int skybox_parameter;
	int var_counter, var_counter2;
	char cam_tile_south, cam_tile_east;
	char tile_south, tile_east;
	char other_offset_south, other_offset_east;
	char tile_to_draw_south_offset, tile_to_draw_east_offset;
	char car_tile_east, car_tile_y;
	unsigned char tiles_to_draw_terr_type_vec[LOOKAHEAD_TILES_DB_SIZE];
	char should_skip_tile[LOOKAHEAD_TILES_DB_SIZE];
	char tiles_to_draw_south[LOOKAHEAD_TILES_DB_SIZE];
	char tiles_to_draw_east[LOOKAHEAD_TILES_DB_SIZE];
	unsigned char tiles_to_draw_elem_type_vec[LOOKAHEAD_TILES_DB_SIZE];
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
	char use_low_poly_version;
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

	char offset_east;
	char offset_south;
	char M_depth_east;
	char M_depth_south;
	char M_width_east;
	char M_width_south;
	char width_idx;

	char low_detail_priority; // for the tile being processed
	char low_detail_threshold; // for this rendering attempt
	unsigned tiles_to_discard;
	unsigned discarded_tiles;
	char debug_overlay_str[60];
	char attempts_count;
	char is_last_attempt;
	char has_attempt_failed;

	var_DC[0] = 0;
	var_DC[1] = 0;
	if (video_flag5_is0 == 0 || arg_0 == 0) {
		rectptr_unk = rect_array_unk;
		rectptr_unk2 = rect_array_unk2;
	} else {
		rectptr_unk2 = rect_array_unk;
		rectptr_unk = rect_array_unk2;
	}

	if (slow_video_mgmt_copy != 0) {
		var_122 = 8;
		var_rectptr = rect_unk;
		for (si = 0; si < 15; si++) {
			*var_rectptr = cliprect_unk;
			var_rectptr++;
		}
	} else {
		var_122 = 0;
	}

	// Set car position (own or opponent's)
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

	// Set camera position, based on the car position and the camera mode
	if (cameramode == 0) {
		car_rot_x_2 = car_rot_x & 0x3ff;
		car_rot_y_2 = car_rot_y & 0x3ff;
		car_rot_z_2   = car_rot_z & 0x3ff;
		car_rot_matrix = mat_rot_zxy(-car_rot_z, -car_rot_y, -car_rot_x, 0);
		offset_vector.x = 0;
		offset_vector.z = 0;
		offset_vector.y = simd_player.car_height - 6;

		mat_mul_vector(&offset_vector, car_rot_matrix, &car_to_cam_rotated);
		cam_pos.x = car_pos.x + car_to_cam_rotated.x;
		cam_pos.y = car_pos.y + car_to_cam_rotated.y;
		cam_pos.z = car_pos.z + car_to_cam_rotated.z;
	} else if (cameramode == 1) {
		cam_pos.x = state.game_vec1[followOpponentFlag].x;
		cam_pos.z = state.game_vec1[followOpponentFlag].z;
		cam_pos.y = state.game_vec1[followOpponentFlag].y;
	} else if (cameramode == 2) {
		offset_vector.x = 0;
		offset_vector.y = 0;
		offset_vector.z = 0x4000;
		car_rot_matrix = mat_rot_zxy(-car_rot_z, -car_rot_y, -car_rot_x, 0);
		mat_mul_vector(&offset_vector, car_rot_matrix, &car_to_cam_rotated);

		offset_vector.x = 0;
		offset_vector.y = 0;
		offset_vector.z = custom_camera_distance;
		car_rot_matrix = mat_rot_zxy(0, -custom_camera_elevation_angle, polarAngle(car_to_cam_rotated.x, car_to_cam_rotated.z) - custom_camera_azimuth_angle, 0);

		mat_mul_vector(&offset_vector, car_rot_matrix, &car_to_cam_rotated);
		cam_pos.x = car_pos.x + car_to_cam_rotated.x;
		cam_pos.y = car_pos.y + car_to_cam_rotated.y;
		cam_pos.z = car_pos.z + car_to_cam_rotated.z;
	} else if (cameramode == 3) {
		cam_pos.x = trackdata9[state.field_3F7[followOpponentFlag] * 3 + 0];
		cam_pos.y = trackdata9[state.field_3F7[followOpponentFlag] * 3 + 1] + word_44D20 + 0x5A;
		cam_pos.z = trackdata9[state.field_3F7[followOpponentFlag] * 3 + 2];
	}

	// Unknown part; seems to be performing some initialization
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

	// This would normally select the table with the 23 tiles to draw, but
	// SuperSight draws many more. We still need the original table to properly
	// convert between cam-based coordinates (width, depth) and absolute
	// (east, south)
	heading = select_cliprect_rotate(car_rot_z_3, car_rot_y_2, car_rot_x_2, arg_cliprectptr, 0);
	lookahead_tiles = lookahead_tiles_tables[(heading & 0x3FF) >> 7];

	var_mat = *mat_rot_zxy(car_rot_z_3, car_rot_y_2, 0, 1);
	offset_vector.x = 0;
	offset_vector.y = 0;
	offset_vector.z = 0x3E8;
	mat_mul_vector(&offset_vector, &var_mat, &var_vec8);
	if (var_vec8.z > 0) {
		skybox_parameter = 1;
	} else {
		skybox_parameter = -1;
	}

	// Draw 8 shapes (still TBD what they are)
	// SuperSight: draw at any detail level
	if (1) {
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
				offset_vector.x = 0;
				offset_vector.y = 0xAE6 - cam_pos.y;
				offset_vector.z = 0x3A98; //15000
				mat_mul_vector(&offset_vector, &var_mat2, &car_to_cam_rotated);
				car_to_cam_rotated.z = 0x3A98; //15000
				mat_mul_vector(&car_to_cam_rotated, &var_mat, &currenttransshape->pos);
				if (currenttransshape->pos.z > 0xC8) {
					currenttransshape->shapeptr = off_3BE44[var_counter];
					currenttransshape->rotvec.z = -car_rot_x_2;
					var_transformresult = transformed_shape_op(&currenttransshape[0]);
					(void) var_transformresult; // we cannot be out of memory as we are just starting to process
				}
			}
		}
	}

/*
; -----------------------------------------------------------------------------------------------
*/

	cam_tile_east = cam_pos.x >> 0xA;
	cam_tile_south = -((cam_pos.z >> 0xA) - 0x1D);

	for (si = 0; si < LOOKAHEAD_TILES_DB_SIZE; si++) {
		should_skip_tile[si] = 0;
	}

	// Calculate the matrix to convert depth-width in east-south coords
	// Use the original lookahead_tiles tables, noticing that its first two
	// elements are the east and south offsets of the farthest tile from the
	// cam (located at depth = 4, width = +- 2)
	M_depth_east = lookahead_tiles[0] == 4 ? 1 : lookahead_tiles[0] == -4 ? -1 : 0;
	M_depth_south = lookahead_tiles[1] == 4 ? 1 : lookahead_tiles[1] == -4 ? -1 : 0;
	M_width_east = lookahead_tiles[0] == 2 ? 1 : lookahead_tiles[0] == -2 ? -1 : 0;
	M_width_south = lookahead_tiles[1] == 2 ? 1 : lookahead_tiles[1] == -2 ? -1 : 0;

	// Cycle on the tiles to draw, determine if they really need to be drawn
	for (si = LOOKAHEAD_TILES_DB_SIZE - 1; si >= 0; si--) {

		// Skip if a previous iteration determined this tile is not needed
		// (happens for multi-tile elements)
		if (should_skip_tile[si] != 0)
			continue;

		offset_east
			= lookahead_tiles_db[si].depth * M_depth_east
			+ lookahead_tiles_db[si].width * M_width_east;
		offset_south
			= lookahead_tiles_db[si].depth * M_depth_south
			+ lookahead_tiles_db[si].width * M_width_south;

		tile_east = cam_tile_east + offset_east;
		tile_south = cam_tile_south + offset_south;

		// Skip if tile is out of bounds
		if (! (tile_east >= 0 && tile_east <= 0x1D && tile_south >= 0 && tile_south <= 0x1D)) {
			should_skip_tile[si] = 2;
			continue;
		}

		elem_map_value = td14_elem_map_main[tile_east + trackrows[tile_south]];
		terr_map_value = td15_terr_map_main[tile_east + terrainrows[tile_south]];

		if (elem_map_value != 0) {
			if (terr_map_value >= 7 && terr_map_value < 0xB) {
				elem_map_value = subst_hillroad_track(terr_map_value, elem_map_value);
				terr_map_value = 0;
			}
		}

		if (reveal_illusions == 0) {
			// Found a filler tile (non-main tile of a multitile component)
			// Process the main tile of the component instead (the NW one)
			if (elem_map_value == 0xFD) {
				tile_east--;
				tile_south--;
				elem_map_value = td14_elem_map_main[tile_east + trackrows[tile_south]];
				terr_map_value = td15_terr_map_main[tile_east + terrainrows[tile_south]];
			} else if (elem_map_value == 0xFE) {
				tile_south--;
				elem_map_value = td14_elem_map_main[tile_east + trackrows[tile_south]];
				terr_map_value = td15_terr_map_main[tile_east + terrainrows[tile_south]];
			} else if (elem_map_value == 0xFF) {
				tile_east--;
				elem_map_value = td14_elem_map_main[tile_east + trackrows[tile_south]];
				terr_map_value = td15_terr_map_main[tile_east + terrainrows[tile_south]];
			}

			// Recalculate the offset (needed in case we hit a filler tile)
			offset_east = tile_east - cam_tile_east;
			offset_south = tile_south - cam_tile_south;
		}
		else
		{
			// Reveal illusions on: just skip the filler tile -- the main tile
			// will be processed when the scan process finds it
			if (   elem_map_value == 0xFD
				|| elem_map_value == 0xFE
				|| elem_map_value == 0xFF)
			{
				should_skip_tile[si] = 1;
			}
		}

		tiles_to_draw_terr_type_vec[si] = terr_map_value;

		tiles_to_draw_east[si] = tile_east;
		tiles_to_draw_south[si] = tile_south;
		tiles_to_draw_elem_type_vec[si] = elem_map_value;

		if (elem_map_value == 0) {
			continue;
		}

		idx = trkObjectList[elem_map_value].ss_multiTileFlag;
		if (idx == 0 || reveal_illusions > 0) {
			continue;
		}

		for (di = 0; di < si; di++) {
			// Look the future tiles to process (i.e. with lower index, since si
			// counts backwards) and remove those which belong to the same
			// multi-tile component as this tile
			other_offset_east
				= lookahead_tiles_db[di].depth * M_depth_east
				+ lookahead_tiles_db[di].width * M_width_east;
			other_offset_south
				= lookahead_tiles_db[di].depth * M_depth_south
				+ lookahead_tiles_db[di].width * M_width_south;

			if (idx == 1) {
				if (other_offset_east == offset_east
					&& (other_offset_south == offset_south || other_offset_south == offset_south + 1))
				{
					should_skip_tile[di] = 1;
				}
			}
			if (idx == 2) {
				if ((other_offset_east == offset_east || other_offset_east == offset_east + 1)
					&& other_offset_south == offset_south)
				{
					should_skip_tile[di] = 1;
				}
			}
			if (idx == 3) {
				if (
					   (other_offset_east == offset_east || other_offset_east == offset_east + 1)
					&& (other_offset_south == offset_south || other_offset_south == offset_south + 1))
				{
					should_skip_tile[di] = 1;
				}
			}
		}
	}

//; -----------------------------------------------------------------------------

	// Draw own wheels
	var_3C = -1;
	var_6C = 0;
	if (cameramode != 0 || followOpponentFlag != 0) {

		if (state.playerstate.car_crashBmpFlag != 2) {

			car_rot_matrix = mat_rot_zxy(-state.playerstate.car_rotate.z, -state.playerstate.car_rotate.y, -state.playerstate.car_rotate.x, 0);
			idx = -1;
			di = -1;
			for (var_counter2 = 0; var_counter2 < 4; var_counter2++) {
				offset_vector = simd_player.wheel_coords[var_counter2];
				mat_mul_vector(&offset_vector, car_rot_matrix, &var_vec8); //; rotating car wheels, maybe?
				// Tile where the wheel is standing
				tile_east = (var_vec8.x + state.playerstate.car_posWorld1.lx) >> 16; // bits 16-24
				tile_south = -(((var_vec8.z + state.playerstate.car_posWorld1.lz) >> 16) - 0x1D);

				for (si = LOOKAHEAD_TILES_DB_SIZE - 1; si > idx; si--) {
					if (should_skip_tile[si] == 2) {
						continue;
					}

					offset_east
						= lookahead_tiles_db[si].depth * M_depth_east
						+ lookahead_tiles_db[si].width * M_width_east;
					offset_south
						= lookahead_tiles_db[si].depth * M_depth_south
						+ lookahead_tiles_db[si].width * M_width_south;

					if (offset_east + cam_tile_east == tile_east
						&& offset_south + cam_tile_south == tile_south)
					{
						var_3C = tile_east;
						var_60 = tile_south;
						idx = si;
						di = var_counter2;
					}
				}
			}

			if (di != -1) {
				if (state.playerstate.car_surfaceWhl[0] != 4 || state.playerstate.car_surfaceWhl[1] != 4 || state.playerstate.car_surfaceWhl[2] != 4 || state.playerstate.car_surfaceWhl[3] != 4) {
					offset_vector.x = 0;
					offset_vector.z = 0;
					offset_vector.y = 0x7530;
					mat_mul_vector(&offset_vector, car_rot_matrix, &var_vec8);
					mat_mul_vector(&var_vec8, &mat_temp, &offset_vector);
					if (offset_vector.z <= 0) {
						var_6C = -0x800 ;
					} else {
						var_6C = 0x800;
					}
				}
			}
		}
	}

	// Draw opponent's wheels
	var_4A = -1;
	var_A4 = 0;
	if (gameconfig.game_opponenttype != 0) {

		if (cameramode != 0 || followOpponentFlag == 0) {
			if (state.opponentstate.car_crashBmpFlag != 2) {
				car_rot_matrix = mat_rot_zxy(-state.opponentstate.car_rotate.z, -state.opponentstate.car_rotate.y, -state.opponentstate.car_rotate.x, 0);
				idx = -1;
				di = -1;

				for (var_counter2 = 0; var_counter2 < 4; var_counter2++) {
					offset_vector = simd_opponent.wheel_coords[var_counter2];
					mat_mul_vector(&offset_vector, car_rot_matrix, &var_vec8); //; rotating car wheels, maybe?
					tile_east = (var_vec8.x + state.opponentstate.car_posWorld1.lx) >> 16; // bits 16-24
					tile_south = -(((var_vec8.z + state.opponentstate.car_posWorld1.lz) >> 16) - 0x1D);

					for (si = LOOKAHEAD_TILES_DB_SIZE - 1; si > idx; si--) {
						if (should_skip_tile[si] == 2) {
							continue;
						}

						offset_east
							= lookahead_tiles_db[si].depth * M_depth_east
							+ lookahead_tiles_db[si].width * M_width_east;
						offset_south
							= lookahead_tiles_db[si].depth * M_depth_south
							+ lookahead_tiles_db[si].width * M_width_south;

						if (offset_east + cam_tile_east == tile_east
							&& offset_south + cam_tile_south == tile_south)
						{
							var_4A = tile_east;
							var_6E = tile_south;
							idx = si;
							di = var_counter2;
						}
					}
				}

				if (di != -1) {

					if (state.opponentstate.car_surfaceWhl[0] != 4 || state.opponentstate.car_surfaceWhl[1] != 4 || state.opponentstate.car_surfaceWhl[2] != 4 || state.opponentstate.car_surfaceWhl[3] != 4) {
						offset_vector.x = 0;
						offset_vector.y = 0;
						offset_vector.z = 0x7530;
						mat_mul_vector(&offset_vector, car_rot_matrix, &var_vec8);
						mat_mul_vector(&var_vec8, &mat_temp, &offset_vector);
						if (offset_vector.z <= 0) {
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

	discarded_tiles = (LOOKAHEAD_TILES_DB_SIZE - tiles_to_draw_max[graphic_level]);
	attempts_count = 0;
	is_last_attempt = 0;
start_rendering:
	low_detail_threshold = get_low_detail_threshold_at_attempt(attempts_count);
	// With the information collected by the previus tile-scan algorithm,
	// proceed to draw the shapes in each tile. Start from the farthest
	// (painter's algorithm)
	has_attempt_failed = 0;
	for (si = discarded_tiles; si < LOOKAHEAD_TILES_DB_SIZE; si++) {
		if (should_skip_tile[si] != 0) {
			continue;
		}
		tile_east = tiles_to_draw_east[si];
		tile_south = tiles_to_draw_south[si];
		elem_map_value = tiles_to_draw_elem_type_vec[si];
		terr_map_value = tiles_to_draw_terr_type_vec[si];
		// On the first attempt, draw everything at max resolution. If it fails
		// (too many polygons), use the low-polygon version on selected squares
		low_detail_priority = lookahead_tiles_db[si].low_detail_priority;
		use_low_poly_version = (low_detail_priority >= low_detail_threshold);
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

		// Draw the fence
		for (idx = 0; idx < var_counter; idx++) {
			tile_to_draw_east_offset = var_10E[idx * 2] + tile_east;
			tile_to_draw_south_offset = var_10E[idx * 2 + 1] + tile_south;


			// SuperSight: draw at any detail level
			if (1) {
				if (tile_to_draw_east_offset == 0) {
					if (tile_to_draw_south_offset == 0) {
						di = 7;
					} else if (tile_to_draw_south_offset == 0x1D) {
						di = 5;
					} else {
						di = 6;
					}
				} else if (tile_to_draw_east_offset == 0x1D) {
					if (tile_to_draw_south_offset == 0) {
						di = 1;
					} else
					if (tile_to_draw_south_offset == 0x1D) {
						di = 1;
					} else {
						di = 2;
					}
				} else {
					if (tile_to_draw_south_offset == 0) {
						di = 0;
					} else if (tile_to_draw_south_offset == 0x1D) {
						di = 4;
					} else {
						di = -1;
					}
				}

				if (di != -1) { // obj on the border
					var_trkobjectptr = &trkObjectList[fence_TrkObjCodes[di]];
					if (use_low_poly_version == 0) {
						currenttransshape->shapeptr = var_trkobjectptr->ss_shapePtr;
					} else {
						currenttransshape->shapeptr = var_trkobjectptr->ss_loShapePtr;
					}

					currenttransshape->pos.x = trackcenterpos2[tile_to_draw_east_offset] - cam_pos.x;
					currenttransshape->pos.y = -cam_pos.y;
					currenttransshape->pos.z = trackcenterpos[tile_to_draw_south_offset] - cam_pos.z;
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
						has_attempt_failed = 1;
						break;
					}
				}
			}
		}

		// terrain type 0x06: a flat piece of land at an elevated level
		if (terr_map_value != 6) {
			var_hillheight = 0;

			// Special treatment of elevated corners
			if (elem_map_value >= 0x69 && elem_map_value <= 0x6C) {
				for (idx = 0; idx < 4; idx++) {
					if (idx == 0) {
						tile_to_draw_east_offset = tile_east;
						tile_to_draw_south_offset = tile_south;
					} else if (idx == 1) {
						tile_to_draw_east_offset = tile_east + 1;
						tile_to_draw_south_offset = tile_south;
					} else if (idx == 2) {
						tile_to_draw_east_offset = tile_east;
						tile_to_draw_south_offset = tile_south + 1;
					} else if (idx == 3) {
						tile_to_draw_east_offset = tile_east + 1;
						tile_to_draw_south_offset = tile_south + 1;
					}
					terr_map_value = td15_terr_map_main[tile_to_draw_east_offset + terrainrows[tile_to_draw_south_offset]];
					if (terr_map_value != 0) {
						var_trkobject_ptr = &sceneshapes2[terr_map_value];
						currenttransshape->shapeptr = var_trkobject_ptr->ss_shapePtr;
						currenttransshape->pos.x = trackcenterpos2[tile_to_draw_east_offset] - cam_pos.x;
						currenttransshape->pos.y = -cam_pos.y;
						currenttransshape->pos.z = trackcenterpos[tile_to_draw_south_offset] - cam_pos.z;
						currenttransshape->rectptr = &rect_unk2;
						currenttransshape->ts_flags = var_122 | 5;
						currenttransshape->rotvec.x = 0;
						currenttransshape->rotvec.y = 0;
						currenttransshape->rotvec.z = var_trkobject_ptr->ss_rotY;
						currenttransshape->unk = 0x400;
						currenttransshape->material = 0;
						var_transformresult = transformed_shape_op(&currenttransshape[0]);
						if (var_transformresult > 0)
						{
							has_attempt_failed = 1;
							break;
						}
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

		// The rest of the rendering loop still needs to be analyzed in detail.
		// Anyway, the gist is that every tile is associated with various shape,
		// each of which is rendered via a call to `transformed_shape_op`. The
		// result of such fn is checked each time, since a return value of 1
		// means we ran out of memory

		if (terr_map_value != 0) {
			var_trkobject_ptr = &sceneshapes2[terr_map_value];
			currenttransshape->shapeptr = var_trkobject_ptr->ss_shapePtr;
			currenttransshape->pos.x = trackcenterpos2[tile_east] - cam_pos.x;
			currenttransshape->pos.y = var_hillheight - cam_pos.y;
			currenttransshape->pos.z = trackcenterpos[tile_south] - cam_pos.z;
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
			{
				has_attempt_failed = 1;
				break;
			}
		}

		transformedshape_counter = 0;
		curtransshape_ptr = currenttransshape;
		if (elem_map_value == 0) {
			tile_to_draw_east_offset = tile_east;
			tile_to_draw_south_offset = tile_south;
		} else {
			var_trkobject_ptr = &trkObjectList[elem_map_value];
			if ((var_trkobject_ptr->ss_multiTileFlag & 1) != 0) {
				var_5E = trackpos[tile_south];
				tile_to_draw_south_offset = tile_south + 1;
			} else {
				var_5E = trackcenterpos[tile_south];
				tile_to_draw_south_offset = tile_south;
			}

			if ((var_trkobject_ptr->ss_multiTileFlag & 2) != 0) {
				var_3A = trackpos2[1 + tile_east];
				tile_to_draw_east_offset = tile_east + 1;
			} else {
				var_3A = trackcenterpos2[tile_east];
				tile_to_draw_east_offset = tile_east;
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
					{
						has_attempt_failed = 1;
						break;
					}
				}
			}

			if (var_trkobject_ptr->ss_ssOvelay != 0) {
				var_trkobjectptr = &trkObjectList[var_trkobject_ptr->ss_ssOvelay];
				if (use_low_poly_version != 0) {
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
						{
							has_attempt_failed = 1;
							break;
						}
					} else {
						currenttransshape[1].rectptr = &rect_unk6;
						var_4E = 1;
					}
				}
			}

			if (use_low_poly_version != 0) {
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
				{
					has_attempt_failed = 1;
					break;
				}
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

				if (tile_east == startcol2 && tile_south == startrow2) {
					var_12A = 0;
				} else {
					var_12A = -1;
				}
			}

			var_4C = trackdata19[tile_east + trackrows[tile_south]];
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

		if ((var_3C == tile_east || var_3C == tile_to_draw_east_offset) && (var_60 == tile_south || var_60 == tile_to_draw_south_offset)) {
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

			if (use_low_poly_version != 0) {
				curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_loShapePtr;
			} else {
				curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_shapePtr;
				sub_204AE(&game3dshapes[0x0AD4 / sizeof(struct SHAPE3D)].shape3d_verts[8], state.playerstate.car_steeringAngle, &state.playerstate.car_rc2, word_443E8, carshapevecs, &carshapevec);
			}

			if (slow_video_mgmt_copy != 0) {
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

		if ((var_4A == tile_east) || (var_4A == tile_to_draw_east_offset)) {
			if ((var_6E == tile_south) || (var_6E == tile_to_draw_south_offset)) {
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

				if (use_low_poly_version != 0) {
					curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_loShapePtr;
				} else {
					curtransshape_ptr->shapeptr = var_trkobject_ptr->ss_shapePtr;
					sub_204AE(&game3dshapes[0x0AEA / sizeof(struct SHAPE3D)].shape3d_verts[8], state.opponentstate.car_steeringAngle, &state.opponentstate.car_rc2, word_4448A, oppcarshapevecs, &oppcarshapevec);
				}

				if (slow_video_mgmt_copy != 0) {
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
			if ((tile_east == startcol2 || tile_to_draw_east_offset == startcol2) && (tile_south == startrow2 || tile_to_draw_south_offset == startrow2)) {

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

		if (transformedshape_counter != 0) {
			if (transformedshape_counter > 1) {
				heapsort_by_order(transformedshape_counter, transformedshape_zarray, transformedshape_indices);
			}

			// Draw red overlights on the brake lights on own and opponent's car
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
				{
					has_attempt_failed = 1;
					break;
				}

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
	if ((si < LOOKAHEAD_TILES_DB_SIZE || has_attempt_failed > 0) && ! is_last_attempt)
	{
		// Rendering failed (due to out-of-memory).
		// If this was the first attempt (i.e. drawing everything with max
		// detail), try to just drop the detail: this alone should reduce the #
		// of polygons needed by about 30%. Otherwise, start to drop tiles.
		++attempts_count;
		if (attempts_count > 1) {
			if (graphic_level == 0)
			{
				tiles_to_discard = LOOKAHEAD_TILES_DB_SIZE - si;
				if (tiles_to_discard < 5) tiles_to_discard = 5;
				if (tiles_to_discard > 30) tiles_to_discard = 30;
			}
			else
			{
				tiles_to_discard = 20;
			}

			discarded_tiles += tiles_to_discard;
			if (discarded_tiles > LOOKAHEAD_TILES_DB_SIZE - 4) {
				discarded_tiles = LOOKAHEAD_TILES_DB_SIZE - 4;
				is_last_attempt = 1;
			}
		}
		polyinfo_reset();
		goto start_rendering;
	}

	if (display_debug_overlay)
	{
		// Debug: print discarded tiles
		_sprintf(
			debug_overlay_str,
			"Polys: %3u, mem: %5u, fails: %u, discards: %2u, reveal: %s",
			polyinfonumpolys, polyinfoptrnext, attempts_count, discarded_tiles,
			reveal_illusions ? "on" : "off");
	}

	// Draw the skybox
	var_132 = skybox_op(arg_0, arg_cliprectptr, skybox_parameter, &var_mat, car_rot_z_3, car_rot_x_2, cam_pos.y);
	sprite_set_1_size(0, 0x140, arg_cliprectptr->top, arg_cliprectptr->bottom);
	get_a_poly_info();

	// This supposedly draws the explosion. The fact that it cycles three
	// different patterns, each 4 frames long, seems to corroborate the
	// hypothesis
	for (si = 0; si < 2; si++) {
		if (var_DC[si] == 0) {
			continue;
		}
		if (slow_video_mgmt_copy == 0) {
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
			offset_vector.x = (var_rectptr->right + var_rectptr->left) >> 1;
			offset_vector.y = (var_rectptr->top + var_rectptr->bottom) >> 1;
			idx = var_rectptr->right - var_rectptr->left;
			var_counter = var_rectptr->bottom - var_rectptr->top;
			if (var_counter > idx) {
				idx = var_counter;
			}

			di = (state.game_frame >> 2) % 3 ;
			var_counter = ((long)idx << 8) / (long)sdgame2_widths[di];
			shape_op_explosion(var_counter, sdgame2shapes[di], offset_vector.x, offset_vector.y);
		}
	}

/*
; --------------------------------------------------------
*/

	// Depict windscreen cracking after a crash
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
			if (slow_video_mgmt_copy != 0) {
				rect_union(init_crak(state.game_frame - si, arg_cliprectptr->top, arg_cliprectptr->bottom - arg_cliprectptr->top), rect_unk, rect_unk);
			} else {
				init_crak(state.game_frame - si, arg_cliprectptr->top, arg_cliprectptr->bottom - arg_cliprectptr->top);
			}
		} else if (var_stateptr->car_crashBmpFlag == 2) {
			if (slow_video_mgmt_copy != 0) {
				rect_union(do_sinking(state.game_frame - si, arg_cliprectptr->top, arg_cliprectptr->bottom - arg_cliprectptr->top), rect_unk, rect_unk);
			} else {
				do_sinking(state.game_frame - si, arg_cliprectptr->top, arg_cliprectptr->bottom - arg_cliprectptr->top);
			}
		}
	}

	if (display_debug_overlay)
	{
		font_set_fontdef2(fontnptr);

		// Print rendering engine debug infos
		si = (attempts_count == 0) ? 15 : attempts_count == 1 ? 14 : 12; // white, yellow, red
		rect_union(intro_draw_text(debug_overlay_str, 0x0C, roofbmpheight + 12, si, 0), &rect_unk11, &rect_unk11);

		// Print camera coords
		if (cameramode == 2)
		{
			_sprintf(
				debug_overlay_str,
				"Cam: dist: %5d, azimuth: %6d, elevation: %4d",
				custom_camera_distance, custom_camera_azimuth_angle, custom_camera_elevation_angle);
		}
		else
		{
			_sprintf(debug_overlay_str, " ");
		}
		rect_union(intro_draw_text(debug_overlay_str, 0x0C, roofbmpheight + 2, si, 0), &rect_unk11, &rect_unk11);

		// Reset text color to black
		rect_union(intro_draw_text(" ", 0x0C, roofbmpheight + 2, 0, 0), &rect_unk11, &rect_unk11);
		font_set_fontdef();
	}

	// Show elapsed time
	if (game_replay_mode == 0) {
		if (state.game_inputmode != 0) {
			format_frame_as_string(&resID_byte1, elapsed_time1 + elapsed_time2, 0);
			font_set_fontdef2(fontledresptr);
			if (slow_video_mgmt_copy != 0) {
				rect_union(intro_draw_text(&resID_byte1, 0x8C, roofbmpheight + 2, dialog_fnt_colour, 0), &rect_unk11, &rect_unk11);
			} else {
				intro_draw_text(&resID_byte1, 0x8C, roofbmpheight + 2, dialog_fnt_colour, 0);
			}

			font_set_fontdef();
		}
	}

	if (slow_video_mgmt_copy != 0) {
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
