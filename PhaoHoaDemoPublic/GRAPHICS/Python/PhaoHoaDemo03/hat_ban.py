from hat import Hat
from global_helper import Global

class HatBan(Hat):
    def __init__(self, toado, vantoc, thoigiansong, mausac):
        self.ToaDo = toado  # tọa độ
        self.VanToc = vantoc  # vận tốc, đúng nghĩa thì dùng kiểu Vector sẽ tốt hơn
        self.ThoiGianSong = thoigiansong  # thời gian sống, thời gian sống <= 0 tức là đã chết

        self.tkshapeid = Global.CreateHatBan(self.ToaDo, mausac)