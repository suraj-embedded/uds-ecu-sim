#!/bin/sh
# vcan0 does not survive reboot - run this after every boot
sudo modprobe vcan can-raw can-isotp 2>/dev/null
sudo ip link add dev vcan0 type vcan 2>/dev/null
sudo ip link set up vcan0
