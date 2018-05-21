{
	"targets": [{
	   "target_name": "cyclic_rc",
       "include_dirs": ["<!(node -e \"require('nan')\")"],
       "sources": ["src/node_crc.cc"],
       "dependencies": ["deps/libcrc/libcrc.gyp:libcrc"]
	}]
}