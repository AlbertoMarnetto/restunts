#! /bin/bash

# Annotate variables via mass search-and-replace
# This puts the .asm files out of sync with the IDA database; however, by
# keeping track of the renames one can update the db in future

replace () {
	for ext in c h asm inc ; do
		d="$( printf '\001' )"

		grep -rl \
				--include "*.$ext" \
				--exclude-dir "build" \
				--exclude-dir ".*" \
				-P "$1" | xargs perl -i -pe "s${d}$1${d}$2${d}g"
	done
}

replace byte_3C09C detail_threshold_by_level
replace off_3C084 lookahead_tiles_tables
replace timertestflag2 graphic_level
replace transformed_shape_op_helper2 projectiondata9_times_ratio
replace transformed_shape_op_helper3 is_facing_camera
replace transformed_shape_op_helper insert_newest_poly_in_poly_linked_list_40ED6
replace word_40ED6 poly_linked_list_40ED6
replace word_45D98 poly_linklist_40ED6_iter4
replace timertestflag slow_video_mgmt
replace do_mrl_textres show_graphic_levels_menu
replace word_3B8EC custom_camera_distance
replace word_3B8EE custom_camera_azimuth_angle # 1024 = 360 deg; increases going ccw
replace word_3B8F0 custom_camera_elevation_angle # 1024 = 360 deg
