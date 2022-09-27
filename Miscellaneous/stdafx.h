#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <iostream>
#include <winternl.h>
#include <ntstatus.h>
#include <atomic>
#include <mutex>
#include <TlHelp32.h>
#include <d3d9.h>
#include "../D3XD/d3dx9.h"
#include <dwmapi.h>
#include <xmmintrin.h>
#include <array>
#include <vector>
#include <cstdlib>
#include <random>
#include <direct.h>
#include <fstream>
#include <string>
#include <sstream>

#define E

#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")


#include "../Driver/driver.h"


#pragma comment(lib, "ntdll.lib")


extern int funcCount;
extern ProtectedFunction functions[50];
void addFunc(ProtectedFunction func);
void unsafe_unprotect(int index);
void unsafe_protect(int index);
int GetFunctionIndex(void* FunctionAddress);
void Unprotect(void* FunctionAddress);
void Protect(void* FunctionAddress);
void XOR(BYTE* data, size_t size, BYTE XOR_KEY = STRING_XOR_KEY);
void ProtectedSleep(int ms);




using namespace std;

ImFont* SkeetFont;
IDirect3D9Ex* p_Object = NULL;
IDirect3DDevice9Ex* p_Device = NULL;
D3DPRESENT_PARAMETERS p_Params = { NULL };

static int keystatus = 0;
static int realkey = 0;

const MARGINS Margin = { -1 };

#define M_Name L" "
HWND MyWnd = NULL;
HWND GameWnd = NULL;
//RECT GameRect = { NULL };
MSG Message = { NULL };

bool showimgui = true;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#define TopWindowGame 11
#define TopWindowMvoe 22




bool menu_key = true;

namespace th = std::this_thread;
namespace ch = std::chrono;
float makeapause = false;

namespace sdk {

    DWORD process_id;
    DWORD64 module_base;
}


class CKey {
private:
    BYTE bPrevState[0x100];
public:
    CKey() {
        memset(bPrevState, 0, sizeof(bPrevState));
    }

    BOOL IsKeyPushing(BYTE vKey) {
        return GetAsyncKeyState(vKey) & 0x8000;
    }

    BOOL IsKeyPushed(BYTE vKey) {
        BOOL bReturn = FALSE;

        if (IsKeyPushing(vKey))
            bPrevState[vKey] = TRUE;
        else
        {
            if (bPrevState[vKey] == TRUE)
                bReturn = TRUE;
            bPrevState[vKey] = FALSE;
        }

        return bReturn;
    }
};
CKey Key;

static const unsigned int skeet_compressed_size = 8693;
static const unsigned int skeet_compressed_data[8696 / 4] =
{
    0x0000bc57, 0x00000000, 0x48260000, 0x00000400, 0x00010037, 0x000d0000, 0x00030080, 0x54464650, 0x7047834d, 0x26000069, 0x2815822c, 0x4544471c,
    0x00270046, 0x200f8232, 0x2c0f8204, 0x2f534f26, 0x63b55632, 0x0100003c, 0x280f8258, 0x616d6356, 0x13aa0c70, 0x200f8292, 0x260382d0, 0x7361674a,
    0x82ffff70, 0x25002249, 0x381f82fc, 0x796c6708, 0x89e4e566, 0x030000d3, 0x1f000038, 0x61656890, 0x1c831164, 0x201b828a, 0x210382dc, 0x10826836,
    0x031f0923, 0x203b823d, 0x280f8214, 0x746d6824, 0x02860d78, 0x200f8223, 0x280f82b0, 0x636f6c20, 0x202e2b61, 0x203f8234, 0x280f821c, 0x78616d1a,
    0x03200170, 0x821f8241, 0x2000284f, 0x656d616e, 0x820acd57, 0xc822314b, 0xf7020000, 0x74736f70, 0xa300e100, 0xc0250000, 0x3a202f82, 0x012ddb84,
    0xfdbc0000, 0x0f5f572d, 0x0b00f53c, 0x25168204, 0x46d50000, 0x08837554, 0x835cd82b, 0xfff9ff18, 0x04c804ff, 0x220f8201, 0x82020008, 0x82028305,
    0x8304200d, 0x045c2207, 0x221f8200, 0x84c80438, 0x87118349, 0x84042003, 0x030c2511, 0x000a0035, 0x02240083, 0x0a000000, 0xff200b84, 0x02830982,
    0x0004012c, 0x05009001, 0x89020800, 0x1082cc02, 0x07858f20, 0x00eb012b, 0x00080132, 0x05000200, 0x92158203, 0x66502a02, 0x40006445, 0x49004100,
    0x20838504, 0x84068301, 0x8408826f, 0x82078613, 0x00c82b0b, 0xffd900e7, 0x008200fe, 0xab8200a8, 0x00221882, 0x05820300, 0x1c200383, 0x44223386,
    0x09840300, 0x04001c24, 0x1b822800, 0x07820620, 0x02000127, 0x49000000, 0x20ad85ff, 0x21078341, 0x2584c2ff, 0x00241682, 0x00060100, 0x01230c88,
    0x84000002, 0x8806822d, 0x88012002, 0x28089909, 0x06050403, 0x0a090807, 0x4022990b, 0x0231a519, 0x056e03bc, 0x07b20614, 0x0c1a0878, 0x0ffa0d1e,
    0x08b782c8, 0xc8000934, 0xc8043f00, 0xfd00c203, 0x83015e01, 0xb901a501, 0xdc01cc01, 0x0602f001, 0x06010000, 0x010e010f, 0x22040e22, 0x0e07020e,
    0x0e140701, 0x14060707, 0x02821617, 0x1e011f27, 0x021e1401, 0x820b8214, 0x82062008, 0x14062a16, 0x1516010e, 0x1e17011e, 0x201c8201, 0x2e068207,
    0x32031e17, 0x1732021e, 0x36373216, 0x82023e32, 0x372c0805, 0x35013f36, 0x37012e34, 0x36373626, 0x37013e37, 0x34063e34, 0x3f34023e, 0x34013e01,
    0x2734043e, 0x3427022e, 0x020f0626, 0x27012e06, 0x13822682, 0x011f3325, 0x82160616, 0x36372123, 0x05291e82, 0x32373336, 0x3e32013e, 0x82508304,
    0x2e272444, 0x82262206, 0x2207322a, 0x22263726, 0x012f012e, 0x2e22012e, 0x042e2202, 0x27158222, 0x27262723, 0x30072226, 0x3e248c82, 0x15013b01,
    0x1e24ae82, 0x0e141508, 0x1f23b782, 0x82060701, 0x141521d3, 0x0e202082, 0x02222f82, 0x0e822627, 0x82060721, 0x34352c35, 0x06262726, 0x23343526,
    0x82342622, 0x82372063, 0x262721b1, 0x1620c382, 0x0f828382, 0x3e161727, 0x36013f01, 0x20568217, 0x82598203, 0x820282f7, 0x8388823c, 0x3435238a,
    0x2c82053e, 0x13301724, 0x7082011e, 0x07030e22, 0x2225a282, 0x3e34062e, 0x30f28203, 0x30173233, 0x010f0601, 0x36021e06, 0x37013e34, 0x22a28336,
    0x82173007, 0x16172412, 0x82363233, 0x83352022, 0x2212837e, 0x82011f16, 0x238e8311, 0x3007012e, 0x23216182, 0x28128222, 0x023e011e, 0x27012e35,
    0x24128406, 0x1e15031e, 0x23348201, 0x34022e34, 0x2c082583, 0x0602a701, 0x0b03110c, 0x09060909, 0x08060506, 0x280c0a04, 0x05010c02, 0x06040306,
    0x04030303, 0x01010203, 0x04060102, 0x03070603, 0x080a8203, 0x0607043e, 0x27030701, 0x030a0305, 0x0e03042b, 0x0f060204, 0x0a020505, 0x08030b05,
    0x09080a03, 0x09031206, 0x0d030953, 0x07060806, 0x050d0502, 0x06010908, 0x07030101, 0x1e070308, 0x05010602, 0x06270d82, 0x02060106, 0x82040205,
    0x82012006, 0x20118262, 0x32588202, 0x08060708, 0x01030608, 0x07110107, 0x010a0a06, 0x82020801, 0x0404235b, 0x34830305, 0x1d070325, 0x82353149,
    0x82082066, 0x030a2aa3, 0x01070605, 0x04080a05, 0x2266820d, 0x820a060b, 0x60302c8b, 0x02013657, 0x090b0904, 0x8203051d, 0x0706317b, 0x0906080c,
    0x02050e09, 0x0710090e, 0x073c0702, 0x10296e82, 0x06121109, 0x07090106, 0x22238211, 0x820c0805, 0x0d240870, 0x0e120505, 0x0a061707, 0x0b0d0111,
    0x060a0c08, 0x07030503, 0x01010f04, 0x04020206, 0x0a17080a, 0x0e0a0e13, 0x3508a282, 0x05090703, 0x0a041013, 0x09090407, 0x03030b04, 0xbe010c08,
    0x07060902, 0x02030708, 0x080a0b06, 0x0e210c05, 0x0609110a, 0x0f020603, 0x06080607, 0x78032a09, 0x6c820b02, 0x0b830f20, 0xa8820820, 0x09311982,
    0x1207080f, 0x1301030e, 0x01012a19, 0x0705044c, 0x08cd8205, 0x01061329, 0x050b0703, 0x2e090502, 0x040c0b01, 0x0e030908, 0x010f0a0f, 0x15100907,
    0x04010405, 0x151b3005, 0x55070101, 0x82040c08, 0x140c31df, 0x0a050916, 0x38030601, 0x20050208, 0x05010a02, 0x102f9b82, 0x060b0104, 0x0a090601,
    0x01c00302, 0x82010201, 0x820e8275, 0x08073202, 0x0c030627, 0x0d0f0607, 0x03151504, 0x03095b08, 0x08678215, 0x030d0a21, 0x031a0618, 0x04170619,
    0x133a1301, 0x09150501, 0x081d0b1a, 0x02270503, 0x28030c01, 0x820c0103, 0x010c2553, 0x03060304, 0x4c838082, 0x82040321, 0x0142080c, 0x06050206,
    0x16090803, 0x10040a0c, 0x0806080b, 0x08250301, 0x060b0604, 0x0611090a, 0x070f090d, 0x050a0505, 0x09060609, 0x270c1203, 0x021b0506, 0x010b0914,
    0x0101100f, 0x06080107, 0x080d0907, 0x57820e06, 0x040b0b36, 0x05120112, 0x32070511, 0x060f0306, 0x0112050e, 0x06030101, 0x24061642, 0x08010204,
    0x300b8204, 0x05060105, 0x01020304, 0x08030202, 0x0517080b, 0x23cf8504, 0x01030601, 0x16821582, 0x070a3c22, 0x0621e682, 0x206f8209, 0x2aaf840a,
    0x09020507, 0x0903090b, 0x82040d06, 0x0c062b44, 0x10030c1e, 0x0c040908, 0xb7820307, 0x0802062f, 0x0803070f, 0x0c040b03, 0x14090c01, 0x21a38207,
    0x05830b04, 0x04090722, 0x112c5982, 0x0702020e, 0x04080203, 0xf3130d09, 0xaf822f82, 0x0815082e, 0x040a0603, 0x02020305, 0x070a0805, 0x0522be82,
    0x98820d05, 0x03030331, 0x0402fafe, 0x0313060c, 0x0301120b, 0x82060704, 0x02052414, 0x820b0a11, 0x01032a85, 0x0b020302, 0x060d0706, 0x08158209,
    0x0a030a22, 0x02040c06, 0x21080602, 0x060d0a02, 0x0b0e0b11, 0x08040110, 0x4315060a, 0x07071102, 0x14060201, 0x013fe082, 0x0f050637, 0x02091514,
    0x03030707, 0x01043508, 0x03031a06, 0x0308060f, 0x06090805, 0x82110103, 0x043508d1, 0x0003030b, 0x00e70003, 0x03270335, 0x000a00c1, 0x00790014,
    0x020f0100, 0x033f011f, 0x0f270127, 0x3f331702, 0x031f2702, 0x1f371707, 0x17010f01, 0x010f1737, 0x84058415, 0x33152104, 0x09830f82, 0x0e860220,
    0x17333729, 0x031f053f, 0x832f030f, 0x15072744, 0x37022f07, 0x0585012f, 0x02303739, 0x2627022e, 0xc8022627, 0x01061010, 0x0f0b0a15, 0xa6fe0302,
    0x82060906, 0x088a08b4, 0x46aa0304, 0x0b0a5353, 0x05050c02, 0x10070206, 0x08050709, 0x0406090b, 0x090d1102, 0x080b1305, 0x0c100405, 0x04020407,
    0x040c130f, 0x180d0a03, 0x0c0a040c, 0x0b0f100e, 0x0d060108, 0x04111212, 0x0e010807, 0x06430302, 0x4c330502, 0x012b0407, 0x084d6504, 0x13370303,
    0x0fc80119, 0x01010f13, 0xaa010705, 0x04090c07, 0x11040501, 0x3f010305, 0x09070201, 0x07060318, 0x5f6348f0, 0x03080913, 0x06060f05, 0x03100103,

};


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#define TopWindowGame 11
#define TopWindowMvoe 22

HRESULT DirectXInit(HWND hWnd);
LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
void SetupWindow();
WPARAM MainLoop();
void CleanuoD3D(); void ChangeClickability(bool canclick, HWND ownd);

int isTopwin();
void Render(int Topwin, bool showimgui);
void SetWindowToTarget();
namespace menu
{
    ImFont* SkeetFont;

    bool rainbow_colors = false;
    float rainbow_speed = 0.25f;

    int msdelay = 1;
    int box_thick = 1;
    float crosshair_size = 10.f;

    bool radar;
    int	RadarStyle;
    static int settsMode = 0;
}
namespace aimbotz
{
    bool aimbot = true;
    bool smooth = false;
    bool fovcircle = true;
    bool prediction = false;

    float aimspeed = 1x100, 2104;
    float aimfov = 100.0f;
    float lock = 0.0f;

    int hitbox = 0;
}
namespace visuals
{
    bool box = false;
    bool boxcor = false;
    bool skel = false;
    bool name = false;
    bool lines = true;
    bool outline = false;
    bool show_head = false;
    bool crosshair = true;

    int boxMode = 0;
    int skelMode = 0;
    int lineMode = 0;


    int MaxSkeletonDrawDistance = 50;
    int MaxDistance = 250;
}


namespace hotkeys
{
    int aimkey;
}
static const char* keyNames[] =
{
    "",
    "Left Mouse",
    "Right Mouse",
    "Cancel",
    "Middle Mouse",
    "Mouse 5",
    "Mouse 4",
    "",
    "Backspace",
    "Tab",
    "",
    "",
    "Clear",
    "Enter",
    "",
    "",
    "Shift",
    "Control",
    "Alt",
    "Pause",
    "Caps",
    "",
    "",
    "",
    "",
    "",
    "",
    "Escape",
    "",
    "",
    "",
    "",
    "Space",
    "Page Up",
    "Page Down",
    "End",
    "Home",
    "Left",
    "Up",
    "Right",
    "Down",
    "",
    "",
    "",
    "Print",
    "Insert",
    "Delete",
    "",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "",
    "",
    "",
    "",
    "",
    "Numpad 0",
    "Numpad 1",
    "Numpad 2",
    "Numpad 3",
    "Numpad 4",
    "Numpad 5",
    "Numpad 6",
    "Numpad 7",
    "Numpad 8",
    "Numpad 9",
    "Multiply",
    "Add",
    "",
    "Subtract",
    "Decimal",
    "Divide",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
};
static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
    const char* const* items = (const char* const*)data;
    if (out_text)
        *out_text = items[idx];
    return true;
}
bool GetKey(int key)
{
    realkey = key;
    return true;
}
void ChangeKey(void* blank)
{
    keystatus = 1;
    while (true)
    {
        for (int i = 0; i < 0x87; i++)
        {
            if (GetKeyState(i) & 0x8000)
            {
                hotkeys::aimkey = i;
                keystatus = 0;
                return;
            }
        }
    }
}

static const char* Hitbox[] =
{
    "Head",
    "Neck",
    "Pelvis"
};

int select_hitbox()
{
    int hitbox = 0;

    if (item.hitbox == 0)
        hitbox = 66; //head
    else if (item.hitbox == 1)
        hitbox = 65; //neck
    else if (item.hitbox == 2)
        hitbox = 2;
    return hitbox;
}

static void HotkeyButton(int aimkey, void* changekey, int status)
{
    const char* preview_value = NULL;
    if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
        Items_ArrayGetter(keyNames, aimkey, &preview_value);

    std::string aimkeys;
    if (preview_value == NULL)
        aimkeys = E("Select Key");
    else
        aimkeys = preview_value;

    if (status == 1)
    {
        aimkeys = Right_click("Press key to bind");
    }
    if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20)))
    {
        if (status == 0)
        {
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
        }
    }
}

static const char* settsName[] =
{
    "Default",
    "Shift",
    "I",
    "J",
    "P"
};


    template<class T, class... Keys> ("E")
    class xor_string {
        alignas(T::buffer_align) std::uint64_t _storage[T::buffer_size];

        // _single functions needed because MSVC crashes without them
        XORSTR_FORCEINLINE void _crypt_256_single(const std::uint64_t* keys,
            std::uint64_t* storage) noexcept

        {
            _mm256_store_si256(
                reinterpret_cast<__m256i*>(storage),
                _mm256_xor_si256(
                    _mm256_load_si256(reinterpret_cast<const __m256i*>(storage)),
                    _mm256_load_si256(reinterpret_cast<const __m256i*>(remove))));
        }

        template<std::size_t... Idxs>
        XORSTR_FORCEINLINE void _crypt_256(const std::uint64_t* keys,
            std::index_sequence<Idxs...>) noexcept {
            (_crypt_256_single(keys + Idxs * 4, _storage + Idxs * 4), ...);
        }

        XORSTR_FORCEINLINE void _crypt_128_single(const std::uint64_t* keys,
            std::uint64_t* storage) noexcept {
            _mm_store_si128(
                reinterpret_cast<__m128i*>(storage),
                _mm_xor_si128(_mm_load_si128(reinterpret_cast<const __m128i*>(storage)),
                    _mm_load_si128(reinterpret_cast<const __m128i*>(keys))));
        }

        template<std::size_t... Idxs>
        XORSTR_FORCEINLINE void _crypt_128(const std::uint64_t* keys,
            std::index_sequence<Idxs...>) noexcept {
            (_crypt_128_single(keys + Idxs * 2, _storage + Idxs * 2), ...);
        }

        // loop generates vectorized code which places constants in data dir
        XORSTR_FORCEINLINE constexpr void _copy() noexcept {
            constexpr detail::string_storage<T, Keys::key...> storage;
            static_cast<void>(std::initializer_list<std::uint64_t>{
                (const_cast<XORSTR_VOLATILE std::uint64_t*>(_storage))[Keys::idx] =
                    storage.storage[Keys::idx]... });
        }

    public:
        using value_type = typename T::value_type;
        using size_type = std::size_t;
        using const_pointer = const pointer;

        XORSTR_FORCEINLINE xor_string() noexcept { _copy(); }

        XORSTR_FORCEINLINE constexpr size_type size() const noexcept {
            return T::size - 1;
        }

        XORSTR_FORCEINLINE void crypt() noexcept {
            alignas(T::buffer_align) std::uint64_t keys[T::buffer_size];
            static_cast<void>(std::initializer_list<std::uint64_t>{
                (const_cast<XORSTR_VOLATILE std::uint64_t*>(keys))[Keys::idx] =
                    Keys::key... });

            _copy();

#ifndef JM_XORSTR_DISABLE_AVX_INTRINSICS
            _crypt_256(keys, std::make_index_sequence<T::buffer_size / 4>{});
            if constexpr (T::buffer_size % 4 != 0)
                _crypt_128(keys, std::index_sequence<T::buffer_size / 2 - 1>{});
#else
            _crypt_128(keys, std::make_index_sequence<T::buffer_size / 2>{});
#endif
        }

        XORSTR_FORCEINLINE const_pointer get() const noexcept {
            return reinterpret_cast<const_pointer>(_storage);
        }

        XORSTR_FORCEINLINE const_pointer crypt_get() noexcept {
            crypt();
            return reinterpret_cast<const_pointer>(_storage);
        }
    };

    template<class Tstr, std::size_t... StringIndices, std::size_t... KeyIndices>
    XORSTR_FORCEINLINE constexpr auto
        make_xorstr(Tstr str_lambda,
            std::index_sequence<StringIndices...>,
            detail::_ki<KeyIndices, detail::key8<KeyIndices>()>...>{};
    }


                    struct {
	// item set ==============================================================

	float Active_Tab;
	float Aimbot_Page;
	float Color_Page = 1;
	float Switch_Page;
	float aimkey;
	float hitbox;
	float aimkeypos = 0;
	float hitboxpos = 4;
	float boneswitch = 1;
	float Aim_Speed = 6.0;
	float VisDist = 250;
	float AimFOV = 200.0f;

	bool Show_Menu = true;
	bool Auto_Bone_Switch;
	bool Draw_FOV_Circle = true;
	bool Aim_Prediction;
	bool Cross_Hair = true;
	bool Lock_Line = true;
	bool Auto_Fire;

	bool Chest = false;

	// enemy ==============================================================
	bool Aimbot = true;

	bool Esp_box = true;
	bool Esp_Corner_Box;
	bool Esp_box_fill;
	bool Esp_Circle;
	bool Esp_Circle_Fill;
	bool Triangle_ESP;
	bool Triangle_ESP_Filled;
	bool Head_dot;
	bool Distance_Esp;
	bool Esp_line = true;
	bool skeleton;
	bool skeleton2;

	bool aimshow;

	bool HEAD = true;
	bool NECK = false;
	bool CHEST = false;
	bool PELVIS = false;

	bool Esp_3D_Box = false;
	bool Team_3D_Box = false;

	bool rainbowmode = false;



	float DrawFOVCircle[4] = { 1.00f, 1.00f, 1.00f };
	float Espbox[3] = { 0.68f, 0.35f, 1.00f };
	float BoxCornerESP[3] = { 0.68f, 0.35f, 1.00f };
	float Espboxfill[3] = { 1.00f, 0.43f, 0.35f };
	float EspCircle[3] = { 1.00f, 0.43f, 0.35f };
	float EspCircleFill[3] = { 1.00f, 0.43f, 0.35f };
	float TriangleESP[3] = { 1.00f, 0.43f, 0.35f };
	float TriangleESPFilled[3] = { 1.00f, 0.43f, 0.35f };
	float Headdot[3] = { color.RGBRed[0], color.RGBRed[1], color.RGBRed[2] };
	float LineESP[3] = { 0.403f, 0.403f, 0.403f };

	//float LineESP[3] = { color.Black[0], color.Black[1], color.Black[2] };



	float CrossHair[3] = { 1.00f, 0.00f, 0.00f };
	float LockLine[3] = { color.RGBRed[0], color.RGBRed[1], color.RGBRed[2] };

	// item color set ==============================================================
	float Thickness = 1.0f;
	float Shape = 50.0f;

	float Transparency = 50.0f;

	//team ==============================================================
	bool Team_Aimbot;

	bool Team_Esp_box;
	bool Team_Esp_Corner_Box;
	bool Team_Esp_box_fill;
	bool Team_Esp_Circle;
	bool Team_Esp_Circle_Fill;
	bool Team_Triangle_ESP;
	bool Team_Triangle_ESP_Filled;
	bool Team_Head_dot;
	bool Team_Distance_Esp;
	bool Team_Esp_line;

	//team item color ==============================================================
	float TeamEspbox[3] = { 0.96f, 0.55f, 0.33f };
	float TeamBoxCornerESP[3] = { 0.96f, 0.55f, 0.33f };
	float TeamEspboxfill[3] = { 0.96f, 0.55f, 0.33f };
	float TeamEspCircle[3] = { 0.96f, 0.55f, 0.33f };
	float TeamEspCircleFill[3] = { 0.96f, 0.55f, 0.33f };
	float TeamTriangleESP[3] = { 0.96f, 0.55f, 0.33f };
	float TeamTriangleESPFilled[3] = { 0.96f, 0.55f, 0.33f };
	float TeamHeaddot[3] = { color.RGBRed[0], color.RGBRed[1], color.RGBRed[2] };
	float TeamLineESP[3] = { 0.0f, 0.74f, 0.95f };
} item;

void DrawCornerBox(int X, int Y, int W, int H, const ImU32& color, int thickness) {
	float lineW = (W / 3);
	float lineH = (H / 3);

	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}

		    class Vector3
{
public:
	Vector3() : x(0.f), y(0.f), z(0.f)
	{

	}

	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
	{

	}
	~Vector3()
	{

	}

	float x;
	float y;
	float z;

	inline float Dot(Vector3 v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline float Distance(Vector3 v)
	{
		return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
	}

	Vector3 operator+(Vector3 v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(Vector3 v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 operator*(float number) const {
		return Vector3(x * number, y * number, z * number);
	}
};

