#! /bin/bash

# Annotate variables via mass search-and-replace
# This puts the .asm files out of sync with the IDA database; however, by
# keeping track of the renames one can update the db in future

022_myrepl () {
	for ext in c h asm inc ; do 
		d="$( printf '\001' )"

		grep -rl \
				--include "*$ext" \
				--exclude-dir "build" \
				--exclude-dir ".*" \
				-P "$1" | xargs perl -i -pe "s${d}$1${d}$2${d}g"
	done
}

022_myrepl poly_linked_list_40ED6_tail poly_linked_list_40ED6_tail
022_myrepl detail_threshold_by_level detail_threshold_by_level
022_myrepl lookahead_tiles_tables lookahead_tiles_tables
022_myrepl detail_level detail_level
022_myrepl projectiondata9_times_ratio projectiondata9_times_ratio
022_myrepl is_facing_camera is_facing_camera
022_myrepl insert_newest_poly_in_poly_linked_list_40ED6 insert_newest_poly_in_poly_linked_list_40ED6
022_myrepl poly_linked_list_40ED6 poly_linked_list_40ED6
022_myrepl poly_linked_list_40ED6_tail poly_linked_list_40ED6_tail

