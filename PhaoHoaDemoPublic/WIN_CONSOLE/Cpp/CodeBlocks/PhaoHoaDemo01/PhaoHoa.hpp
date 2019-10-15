#ifndef _PHAO_HOA_
#define _PHAO_HOA_


#include <vector>
#include <cstdlib>
#include <cmath>
#include "Point.hpp"
#include "Hat.hpp"
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
    Hat hatBan;                 // GIAI ĐOẠN 1. Hạt bắn lên
    std::vector<Hat> listHat;   // GIAI ĐOẠN 2. Danh sách các hạt phát nổ được sinh ra khi hạt bắn lên đã chết
    
    std::vector<Point> listToaDo;  // lưu tất cả tọa độ mà các hạt bắn ra

    int mauSacHat;


    PhaoHoa()
    {
        Point hatBan_toado = Point(Helper::GetRandom(10, Global::WindowWidth - 10), Global::WindowHeight);
        Point hatBan_vantoc = Point(0, -1);
        int hatBan_thoigiansong = Helper::GetRandom(10, 15);

        hatBan = Hat(hatBan_toado, hatBan_vantoc, hatBan_thoigiansong);
        
        mauSacHat = Helper::GetRandom(8, 16);
    }


    // khi phát nổ, khởi tạo danh sách các hạt sáng ngẫu nhiên
    void PhatNo()
    {
        listHat.clear();

        for (int vx = -1; vx <= 1; vx++)
            for (int vy = -1; vy <= 1; vy++)
                if (vx != 0 || vy != 0)
                {
                    Point vantoc = Point(vx, vy);
                    int thoigiansong = 6;

                    Hat hat = Hat(hatBan.ToaDo, vantoc, thoigiansong);
                    listHat.push_back(hat);
                }
    }



    bool CapNhat()
    {
        Global::TextColor(this->mauSacHat);

        if (hatBan.ThoiGianSong > 0)
            return CapNhatGiaiDoan1();
        else
            return CapNhatGiaiDoan2();
    }


private:
    bool CapNhatGiaiDoan1()
    {
        bool ret = hatBan.CapNhat(true);

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
        for (int i = listHat.size() - 1; i >= 0; i--)
        {
            Hat &hat = listHat[i];
            bool ret = hat.CapNhat(false);

            listToaDo.push_back(hat.ToaDo);

            if (ret == false)
            {
                listHat.erase(listHat.begin() + i);
            }
        }

        if (listHat.size() > 0)
            return true;

        for (int i = 0; i < listToaDo.size(); i++)
        {
            Global::GotoXY(listToaDo[i].X, listToaDo[i].Y);
            putchar(' ');
        }

        return false;
    }
};


#endif