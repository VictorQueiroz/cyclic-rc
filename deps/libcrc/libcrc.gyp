{
    "targets": [{
        "target_name": "libcrc",
        "type": "static_library",
        "product_extension": "node",
        "include_dirs": [
            "include"
        ],
        "sources": [
            "src/crc16.c",
            "src/crc8.c",
            "src/crckrmit.c",
            "src/crc32.c",
            "src/crcccitt.c",
            "src/crcsick.c",
            "src/crc64.c",
            "src/crcdnp.c",
            "src/nmea-chk.c"
        ],
        'direct_dependent_settings': {
            'include_dirs': [
              'include'
            ]
        }
    }]
}