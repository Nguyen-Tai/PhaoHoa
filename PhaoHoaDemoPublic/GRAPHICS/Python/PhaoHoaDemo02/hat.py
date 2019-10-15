#!/usr/bin/env python
# -*- coding: utf-8 -*-

from global_helper import Global
from point import *


# hạt sáng
class Hat:
    def __init__(self, toado, vantoc, thoigiansong, mausac):
        self.ToaDo = toado                  # tọa độ
        self.VanToc = vantoc                # vận tốc, đúng nghĩa thì dùng kiểu Vector sẽ tốt hơn
        self.ThoiGianSong = thoigiansong    # thời gian sống, thời gian sống <= 0 tức là đã chết

        self.tkshapeid = Global.CreateHat(self.ToaDo, mausac)


    def CapNhatUI(self):
        Global.winCanvas.move(self.tkshapeid, self.VanToc.x, self.VanToc.y)


    # trả về True nếu hạt còn sống, trả về False nếu hạt đã chết (hết thời gian sống)
    def CapNhat(self):
        if self.ThoiGianSong <= 0:
            return False

        self.ToaDo = Point(self.ToaDo.x + self.VanToc.x, self.ToaDo.y + self.VanToc.y)

        self.ThoiGianSong -= 1

        self.CapNhatUI()

        if (self.ThoiGianSong <= 0):
            Global.winCanvas.delete(self.tkshapeid)

        return (self.ThoiGianSong > 0)

