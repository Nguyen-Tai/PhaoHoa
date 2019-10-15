#ifndef _PHAO_HOA_
#define _PHAO_HOA_


#include <vector>
#include <cstdlib>
#include "Point.hpp"
#include "Hat.hpp"
#include "HatBan.hpp"
#include "Global.hpp"
#include "Helper.hpp"


/*
* Pháo hoa chạy (hàm CapNhat) sẽ giải qua 2 giai đoạn
* GIAI ĐOẠN 1. Một hạt được bắn lên
* GIAI ĐOẠN PHÁT NỔ. Phát sinh các hạt sáng ngẫu nhiên
* GIAI ĐOẠN 2. Lan tỏa các hạt sáng được sinh ra
* */
class PhaoHoa
{
public:
    HatBan hatBan;                 // GIAI ĐOẠN 1. Hạt bắn lên
    std::vector<Hat> listHat;   // GIAI ĐOẠN 2. Danh sách các hạt phát nổ được sinh ra khi hạt bắn lên đã chết

    int mauSacHat;


    PhaoHoa()
    {
        Point hatBan_toado = Point(Helper::GetRandom(100, Global::WindowWidth - 100), Global::WindowHeight);
        Point hatBan_vantoc = Point(0, -12);
        int hatBan_thoigiansong = Helper::GetRandom(25, 50);

        hatBan = HatBan(hatBan_toado, hatBan_vantoc, hatBan_thoigiansong);
        
        mauSacHat = Helper::GetRandom(1, 16);
    }


    // khi phát nổ, khởi tạo danh sách các hạt sáng ngẫu nhiên
    void PhatNo()
    {
        int n = Helper::GetRandom(60, 100);
        listHat.clear();

        for (int i = 0; i < n; i++)
        {
            // vận tốc (X, Y) ngẫu nhiên nằm trong đoạn [-5, 5]
            Point vantoc = Point(-5.f + Helper::GetRandom(110) / 10.f, -5.f + Helper::GetRandom(110) / 10.f);
            int thoigiansong = Helper::GetRandom(20, 30);

            Hat hat = Hat(hatBan.ToaDo, vantoc, thoigiansong);
            listHat.push_back(hat);
        }
    }



    bool CapNhat()
    {
        if (hatBan.ThoiGianSong > 0)
            return CapNhatGiaiDoan1();
        else
            return CapNhatGiaiDoan2();
    }


private:
    bool CapNhatGiaiDoan1()
    {
        setfillstyle(1, WHITE);
        bool ret = hatBan.CapNhat();

        if (ret == false)
        {
            // hạt sáng bắn lên đã chết, đến giai đoạn pháo hoa nổ
            PhatNo();
        }

        return true;
    }


    // trả về true nếu pháo hoa còn sống, trả về false nếu pháo hoa đã chết
    // pháo hoa còn sống nghĩa là còn tồn tại các hạt sáng do nó phát ra
    bool CapNhatGiaiDoan2()
    {
        setfillstyle(1, mauSacHat);

        for (int i = listHat.size() - 1; i >= 0; i--)
        {
            Hat &hat = listHat[i];
            bool ret = hat.CapNhat();

            if (ret == false)
            {
                listHat.erase(listHat.begin() + i);
            }
        }

        if (listHat.size() > 0)
            return true;

        return false;
    }
};


#endif