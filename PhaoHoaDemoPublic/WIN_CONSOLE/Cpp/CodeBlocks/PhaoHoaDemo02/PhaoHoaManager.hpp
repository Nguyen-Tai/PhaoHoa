#ifndef _PHAO_HOA_MANAGER_
#define _PHAO_HOA_MANAGER_


#include <vector>
#include "PhaoHoa.hpp"


class PhaoHoaManager
{
public:
    std::vector<PhaoHoa> ListPhaoHoa;


    const int SoLuongPhaoHoa() const
    {
        return ListPhaoHoa.size();
    }


    PhaoHoaManager()
    {
        this->ListPhaoHoa.push_back(PhaoHoa());
    }


    void CapNhat()
    {
        // BƯỚC 1. Cập nhật nội bộ
        if (this->SoLuongPhaoHoa() < 3 && Helper::GetRandom(10) == 0)
        {
            PhaoHoa phaohoa = PhaoHoa();
            this->ListPhaoHoa.push_back(phaohoa);
        }


        // BƯỚC 2. Cập nhật từng pháo hoa bên trong
        for (int i = ListPhaoHoa.size() - 1; i >= 0; i--)
        {
            PhaoHoa &phaohoa = this->ListPhaoHoa[i];
            bool ret = phaohoa.CapNhat();

            // nếu pháo hoa đã chết, xóa khỏi danh sách
            if (ret == false)
            {
                this->ListPhaoHoa.erase(this->ListPhaoHoa.begin() + i);
            }
        }
    }
};


#endif