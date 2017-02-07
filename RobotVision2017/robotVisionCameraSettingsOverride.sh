#!/bin/bash
v4l2-ctl -d /dev/video0 -c brightness=40
v4l2-ctl -d /dev/video0 -c white_balance_temperature_auto=0
v4l2-ctl -d /dev/video0 -c white_balance_temperature=2500
v4l2-ctl -d /dev/video0 -c saturation=75