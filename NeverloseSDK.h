#pragma once
#include <cstdint>

namespace NeverloseSDK {
    namespace AntiAim {
        inline uintptr_t GetBase() {
            return *(uintptr_t*)0x42500648;
        }

        inline void OverrideHiddenPitch(float Value) {
            uintptr_t Base = GetBase();
            if (!Base)
                return;

            *(float*)(Base + 136) = Value;
            *(bool*)(Base + 140) = true;
        }

        inline void OverrideHiddenYawOffset(float Value) {
            uintptr_t Base = GetBase();
            if (!Base)
                return;

            *(float*)(Base + 128) = Value;
            *(bool*)(Base + 132) = true;
        }
    }

    namespace Exploits {
        inline int ChargedTicks() {
            return *(int*)0x42500660;
        }

        inline bool IsCharging() {
            return *(bool*)0x42500C78;
        }

        inline bool IsCharged() {
            return !IsCharging();
        }

        inline bool IsAvailable() {
            return *(bool*)0x42500974;
        }

        inline bool InRecharge() {
            return *(bool*)0x424B1C9C;
        }

        inline void AllowDefensive(bool Allow = true) {
            *(bool*)0x42506CBC = Allow;
        }

        inline void AllowCharge(bool Allow = true) {
            *(bool*)0x42242658 = Allow;
        }

        inline bool IsPeeking() {
            return *(bool*)0x425073E4;
        }

        inline void ForceCharge() {
            if (IsAvailable() && ChargedTicks() <= 0)
                *(bool*)0x42506CB5 = true;
        }

        inline void ForceTeleport() {
            if (ChargedTicks() > 0)
                *(bool*)0x42500968 = true;
        }
    }
}
