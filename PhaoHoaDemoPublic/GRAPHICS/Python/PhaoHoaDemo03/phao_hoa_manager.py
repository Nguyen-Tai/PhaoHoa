#!/usr/bin/env python
# -*- coding: utf-8 -*-

from global_helper import *
from random import randint
from phao_hoa import *


class PhaoHoaManager:
    def __init__(self):
        self.list_phao_hoa = []

    def CapNhat(self):
        # BƯỚC 1. Cập nhật nội bộ
        if len(self.list_phao_hoa) < 3 and randint(0, 10) == 0:
            phaohoa = PhaoHoa()
            self.list_phao_hoa.append(phaohoa)

        # BƯỚC 2. Cập nhật từng pháo hoa bên trong
        for i in range(len(self.list_phao_hoa) - 1, -1, -1):
            ret = self.list_phao_hoa[i].CapNhat()

            if ret == False:
                del self.list_phao_hoa[i]
