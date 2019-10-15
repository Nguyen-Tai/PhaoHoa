#!/usr/bin/env python
# -*- coding: utf-8 -*-

from hat_ban import HatBan
from hat import *
from point import *
from global_helper import *
from random import randint, uniform, choice


'''
Pháo hoa chạy (hàm CapNhat) sẽ giải qua 2 giai đoạn
GIAI ĐOẠN 1. Một hạt được bắn lên
GIAI ĐOẠN PHÁT NỔ. Phát sinh các hạt sáng ngẫu nhiên
GIAI ĐOẠN 2. Lan tỏa các hạt sáng được sinh ra
'''
class PhaoHoa:
    def __init__(self):
        hatBan_toado = Point(randint(100, Global.WindowWidth - 100), Global.WindowHeight)
        hatBan_vantoc = Point(0, -12)
        hatBan_thoigiansong = randint(25, 45)

        self.mausac = choice(Global.ListColors)

        self.hatBan = HatBan(hatBan_toado, hatBan_vantoc, hatBan_thoigiansong, self.mausac)
        self.listHat = []


    # khi phát nổ, khởi tạo danh sách các hạt sáng ngẫu nhiên
    def PhatNo(self):
        n = randint(40, 80)
        self.listHat = []

        for i in range(n):
            # vận tốc (X, Y) ngẫu nhiên nằm trong đoạn [-5, 5], với X và Y là một số thực
            vantoc = Point(uniform(-5, 5), uniform(-5, 5))
            thoigiansong = randint(20, 30)

            hat = Hat(self.hatBan.ToaDo, vantoc, thoigiansong, self.mausac)
            self.listHat.append(hat)


    def CapNhat(self):
        if self.hatBan.ThoiGianSong > 0:
            return self.CapNhatGiaiDoan1()
        else:
            return self.CapNhatGiaiDoan2()

    def CapNhatGiaiDoan1(self):
        ret = self.hatBan.CapNhat()

        if ret == False:
            # hạt sáng bắn lên đã chết, đến giai đoạn pháo hoa nổ
            self.PhatNo()

        return True


    # trả về True nếu pháo hoa còn sống, trả về False nếu pháo hoa đã chết
    # pháo hoa còn sống nghĩa là còn tồn tại các hạt sáng do nó phát ra
    def CapNhatGiaiDoan2(self):
        for i in range(len(self.listHat) - 1, -1, -1):
            hat = self.listHat[i]
            ret = hat.CapNhat()

            if ret == False:
                del self.listHat[i]

        return len(self.listHat) > 0

