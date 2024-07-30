#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.us.z64'
    config['myimg'] = 'build/us/NGVE.z64'
    config['mapfile'] = 'build/us/NGVE.map'
    config['source_directories'] = ['.']
    config['makeflags'] = ['COMPARE=0']