#include <bits/stdc++.h>
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    static uint64_t get_fixed_random()
    {
        static const uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return FIXED_RANDOM;
    }

    template <typename T>
    size_t operator()(T const &x) const
    {
        if constexpr (is_integral_v<T> || is_enum_v<T>)
            return splitmix64(x + get_fixed_random());

        else if constexpr (is_floating_point_v<T>)
        {
            long double scaled = x * 1e9L;
            uint64_t q = static_cast<uint64_t>(llround(scaled));
            return splitmix64(q + get_fixed_random());
        }

        else if constexpr (is_same_v<T, char>)
            return splitmix64((uint64_t)x + get_fixed_random());

        else if constexpr (is_same_v<T, string>)
        {
            uint64_t h = get_fixed_random();
            for (char c : x)
                h = (h ^ c) * 0x100000001b3ULL; // FNV-1a inspired
            return splitmix64(h);
        }

        else if constexpr (requires { x.first; x.second; })
        {
            // pair-like
            uint64_t a = (*this)(x.first);
            uint64_t b = (*this)(x.second);
            return splitmix64(a ^ (b + 0x9e3779b97f4a7c15 + (a << 6) + (a >> 2)));
        }

        else if constexpr (requires { x.begin(); x.end(); })
        {
            // container-like (vector, set, unordered_set, etc.)
            uint64_t h = get_fixed_random();
            for (auto &v : x)
                h ^= (*this)(v) + 0x9e3779b97f4a7c15 + (h << 6) + (h >> 2);
            return splitmix64(h);
        }

        else
            static_assert(!sizeof(T), "No hash defined for this type");
    }
};