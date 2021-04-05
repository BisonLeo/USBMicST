#include "trigTable.h"
#include <stdbool.h>

#define TABLE_SIZE (4096)
#define PERIOD_SIZE (TABLE_SIZE*2)
#define TABLE_MAX_VALUE (4095)
#define TABLE_MIN_VALUE (0)

const int16_t costable[TABLE_SIZE] =
{4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, \
4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, \
4095, 4095, 4095, 4095, 4095, 4095, 4095, 4094, 4094, 4094, 4094, \
4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, 4094, \
4094, 4094, 4094, 4094, 4094, 4094, 4093, 4093, 4093, 4093, 4093, \
4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4093, 4092, \
4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, 4092, \
4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4091, 4090, \
4090, 4090, 4090, 4090, 4090, 4090, 4090, 4090, 4089, 4089, 4089, \
4089, 4089, 4089, 4089, 4089, 4088, 4088, 4088, 4088, 4088, 4088, \
4088, 4088, 4087, 4087, 4087, 4087, 4087, 4087, 4087, 4086, 4086, \
4086, 4086, 4086, 4086, 4086, 4085, 4085, 4085, 4085, 4085, 4085, \
4085, 4084, 4084, 4084, 4084, 4084, 4084, 4083, 4083, 4083, 4083, \
4083, 4083, 4082, 4082, 4082, 4082, 4082, 4081, 4081, 4081, 4081, \
4081, 4081, 4080, 4080, 4080, 4080, 4080, 4079, 4079, 4079, 4079, \
4079, 4078, 4078, 4078, 4078, 4078, 4077, 4077, 4077, 4077, 4077, \
4076, 4076, 4076, 4076, 4076, 4075, 4075, 4075, 4075, 4074, 4074, \
4074, 4074, 4074, 4073, 4073, 4073, 4073, 4072, 4072, 4072, 4072, \
4071, 4071, 4071, 4071, 4070, 4070, 4070, 4070, 4069, 4069, 4069, \
4069, 4068, 4068, 4068, 4068, 4067, 4067, 4067, 4067, 4066, 4066, \
4066, 4066, 4065, 4065, 4065, 4065, 4064, 4064, 4064, 4063, 4063, \
4063, 4063, 4062, 4062, 4062, 4062, 4061, 4061, 4061, 4060, 4060, \
4060, 4060, 4059, 4059, 4059, 4058, 4058, 4058, 4057, 4057, 4057, \
4057, 4056, 4056, 4056, 4055, 4055, 4055, 4054, 4054, 4054, 4053, \
4053, 4053, 4053, 4052, 4052, 4052, 4051, 4051, 4051, 4050, 4050, \
4050, 4049, 4049, 4049, 4048, 4048, 4048, 4047, 4047, 4047, 4046, \
4046, 4046, 4045, 4045, 4045, 4044, 4044, 4044, 4043, 4043, 4042, \
4042, 4042, 4041, 4041, 4041, 4040, 4040, 4040, 4039, 4039, 4039, \
4038, 4038, 4037, 4037, 4037, 4036, 4036, 4036, 4035, 4035, 4034, \
4034, 4034, 4033, 4033, 4032, 4032, 4032, 4031, 4031, 4031, 4030, \
4030, 4029, 4029, 4029, 4028, 4028, 4027, 4027, 4027, 4026, 4026, \
4025, 4025, 4025, 4024, 4024, 4023, 4023, 4022, 4022, 4022, 4021, \
4021, 4020, 4020, 4020, 4019, 4019, 4018, 4018, 4017, 4017, 4017, \
4016, 4016, 4015, 4015, 4014, 4014, 4014, 4013, 4013, 4012, 4012, \
4011, 4011, 4010, 4010, 4010, 4009, 4009, 4008, 4008, 4007, 4007, \
4006, 4006, 4005, 4005, 4005, 4004, 4004, 4003, 4003, 4002, 4002, \
4001, 4001, 4000, 4000, 3999, 3999, 3998, 3998, 3997, 3997, 3997, \
3996, 3996, 3995, 3995, 3994, 3994, 3993, 3993, 3992, 3992, 3991, \
3991, 3990, 3990, 3989, 3989, 3988, 3988, 3987, 3987, 3986, 3986, \
3985, 3985, 3984, 3984, 3983, 3983, 3982, 3982, 3981, 3981, 3980, \
3980, 3979, 3978, 3978, 3977, 3977, 3976, 3976, 3975, 3975, 3974, \
3974, 3973, 3973, 3972, 3972, 3971, 3971, 3970, 3969, 3969, 3968, \
3968, 3967, 3967, 3966, 3966, 3965, 3965, 3964, 3963, 3963, 3962, \
3962, 3961, 3961, 3960, 3959, 3959, 3958, 3958, 3957, 3957, 3956, \
3956, 3955, 3954, 3954, 3953, 3953, 3952, 3952, 3951, 3950, 3950, \
3949, 3949, 3948, 3947, 3947, 3946, 3946, 3945, 3945, 3944, 3943, \
3943, 3942, 3942, 3941, 3940, 3940, 3939, 3939, 3938, 3937, 3937, \
3936, 3936, 3935, 3934, 3934, 3933, 3932, 3932, 3931, 3931, 3930, \
3929, 3929, 3928, 3928, 3927, 3926, 3926, 3925, 3924, 3924, 3923, \
3923, 3922, 3921, 3921, 3920, 3919, 3919, 3918, 3917, 3917, 3916, \
3916, 3915, 3914, 3914, 3913, 3912, 3912, 3911, 3910, 3910, 3909, \
3908, 3908, 3907, 3906, 3906, 3905, 3904, 3904, 3903, 3902, 3902, \
3901, 3900, 3900, 3899, 3898, 3898, 3897, 3896, 3896, 3895, 3894, \
3894, 3893, 3892, 3892, 3891, 3890, 3890, 3889, 3888, 3888, 3887, \
3886, 3885, 3885, 3884, 3883, 3883, 3882, 3881, 3881, 3880, 3879, \
3878, 3878, 3877, 3876, 3876, 3875, 3874, 3874, 3873, 3872, 3871, \
3871, 3870, 3869, 3869, 3868, 3867, 3866, 3866, 3865, 3864, 3863, \
3863, 3862, 3861, 3861, 3860, 3859, 3858, 3858, 3857, 3856, 3855, \
3855, 3854, 3853, 3852, 3852, 3851, 3850, 3850, 3849, 3848, 3847, \
3847, 3846, 3845, 3844, 3844, 3843, 3842, 3841, 3840, 3840, 3839, \
3838, 3837, 3837, 3836, 3835, 3834, 3834, 3833, 3832, 3831, 3831, \
3830, 3829, 3828, 3827, 3827, 3826, 3825, 3824, 3824, 3823, 3822, \
3821, 3820, 3820, 3819, 3818, 3817, 3816, 3816, 3815, 3814, 3813, \
3813, 3812, 3811, 3810, 3809, 3809, 3808, 3807, 3806, 3805, 3805, \
3804, 3803, 3802, 3801, 3800, 3800, 3799, 3798, 3797, 3796, 3796, \
3795, 3794, 3793, 3792, 3791, 3791, 3790, 3789, 3788, 3787, 3787, \
3786, 3785, 3784, 3783, 3782, 3782, 3781, 3780, 3779, 3778, 3777, \
3776, 3776, 3775, 3774, 3773, 3772, 3771, 3771, 3770, 3769, 3768, \
3767, 3766, 3765, 3765, 3764, 3763, 3762, 3761, 3760, 3759, 3759, \
3758, 3757, 3756, 3755, 3754, 3753, 3753, 3752, 3751, 3750, 3749, \
3748, 3747, 3746, 3746, 3745, 3744, 3743, 3742, 3741, 3740, 3739, \
3739, 3738, 3737, 3736, 3735, 3734, 3733, 3732, 3731, 3730, 3730, \
3729, 3728, 3727, 3726, 3725, 3724, 3723, 3722, 3722, 3721, 3720, \
3719, 3718, 3717, 3716, 3715, 3714, 3713, 3712, 3711, 3711, 3710, \
3709, 3708, 3707, 3706, 3705, 3704, 3703, 3702, 3701, 3700, 3700, \
3699, 3698, 3697, 3696, 3695, 3694, 3693, 3692, 3691, 3690, 3689, \
3688, 3687, 3686, 3685, 3685, 3684, 3683, 3682, 3681, 3680, 3679, \
3678, 3677, 3676, 3675, 3674, 3673, 3672, 3671, 3670, 3669, 3668, \
3667, 3666, 3665, 3665, 3664, 3663, 3662, 3661, 3660, 3659, 3658, \
3657, 3656, 3655, 3654, 3653, 3652, 3651, 3650, 3649, 3648, 3647, \
3646, 3645, 3644, 3643, 3642, 3641, 3640, 3639, 3638, 3637, 3636, \
3635, 3634, 3633, 3632, 3631, 3630, 3629, 3628, 3627, 3626, 3625, \
3624, 3623, 3622, 3621, 3620, 3619, 3618, 3617, 3616, 3615, 3614, \
3613, 3612, 3611, 3610, 3609, 3608, 3607, 3606, 3605, 3604, 3603, \
3602, 3601, 3600, 3599, 3598, 3597, 3596, 3595, 3594, 3593, 3592, \
3591, 3590, 3589, 3588, 3587, 3586, 3584, 3583, 3582, 3581, 3580, \
3579, 3578, 3577, 3576, 3575, 3574, 3573, 3572, 3571, 3570, 3569, \
3568, 3567, 3566, 3565, 3564, 3562, 3561, 3560, 3559, 3558, 3557, \
3556, 3555, 3554, 3553, 3552, 3551, 3550, 3549, 3548, 3547, 3545, \
3544, 3543, 3542, 3541, 3540, 3539, 3538, 3537, 3536, 3535, 3534, \
3533, 3531, 3530, 3529, 3528, 3527, 3526, 3525, 3524, 3523, 3522, \
3521, 3520, 3518, 3517, 3516, 3515, 3514, 3513, 3512, 3511, 3510, \
3509, 3507, 3506, 3505, 3504, 3503, 3502, 3501, 3500, 3499, 3498, \
3496, 3495, 3494, 3493, 3492, 3491, 3490, 3489, 3488, 3486, 3485, \
3484, 3483, 3482, 3481, 3480, 3479, 3477, 3476, 3475, 3474, 3473, \
3472, 3471, 3470, 3468, 3467, 3466, 3465, 3464, 3463, 3462, 3460, \
3459, 3458, 3457, 3456, 3455, 3454, 3452, 3451, 3450, 3449, 3448, \
3447, 3446, 3444, 3443, 3442, 3441, 3440, 3439, 3438, 3436, 3435, \
3434, 3433, 3432, 3431, 3429, 3428, 3427, 3426, 3425, 3424, 3423, \
3421, 3420, 3419, 3418, 3417, 3416, 3414, 3413, 3412, 3411, 3410, \
3408, 3407, 3406, 3405, 3404, 3403, 3401, 3400, 3399, 3398, 3397, \
3396, 3394, 3393, 3392, 3391, 3390, 3388, 3387, 3386, 3385, 3384, \
3382, 3381, 3380, 3379, 3378, 3377, 3375, 3374, 3373, 3372, 3371, \
3369, 3368, 3367, 3366, 3365, 3363, 3362, 3361, 3360, 3359, 3357, \
3356, 3355, 3354, 3352, 3351, 3350, 3349, 3348, 3346, 3345, 3344, \
3343, 3342, 3340, 3339, 3338, 3337, 3335, 3334, 3333, 3332, 3331, \
3329, 3328, 3327, 3326, 3324, 3323, 3322, 3321, 3320, 3318, 3317, \
3316, 3315, 3313, 3312, 3311, 3310, 3308, 3307, 3306, 3305, 3303, \
3302, 3301, 3300, 3299, 3297, 3296, 3295, 3294, 3292, 3291, 3290, \
3289, 3287, 3286, 3285, 3284, 3282, 3281, 3280, 3279, 3277, 3276, \
3275, 3273, 3272, 3271, 3270, 3268, 3267, 3266, 3265, 3263, 3262, \
3261, 3260, 3258, 3257, 3256, 3255, 3253, 3252, 3251, 3249, 3248, \
3247, 3246, 3244, 3243, 3242, 3241, 3239, 3238, 3237, 3235, 3234, \
3233, 3232, 3230, 3229, 3228, 3226, 3225, 3224, 3223, 3221, 3220, \
3219, 3217, 3216, 3215, 3214, 3212, 3211, 3210, 3208, 3207, 3206, \
3205, 3203, 3202, 3201, 3199, 3198, 3197, 3195, 3194, 3193, 3192, \
3190, 3189, 3188, 3186, 3185, 3184, 3182, 3181, 3180, 3178, 3177, \
3176, 3175, 3173, 3172, 3171, 3169, 3168, 3167, 3165, 3164, 3163, \
3161, 3160, 3159, 3157, 3156, 3155, 3154, 3152, 3151, 3150, 3148, \
3147, 3146, 3144, 3143, 3142, 3140, 3139, 3138, 3136, 3135, 3134, \
3132, 3131, 3130, 3128, 3127, 3126, 3124, 3123, 3122, 3120, 3119, \
3118, 3116, 3115, 3114, 3112, 3111, 3110, 3108, 3107, 3106, 3104, \
3103, 3101, 3100, 3099, 3097, 3096, 3095, 3093, 3092, 3091, 3089, \
3088, 3087, 3085, 3084, 3083, 3081, 3080, 3078, 3077, 3076, 3074, \
3073, 3072, 3070, 3069, 3068, 3066, 3065, 3064, 3062, 3061, 3059, \
3058, 3057, 3055, 3054, 3053, 3051, 3050, 3049, 3047, 3046, 3044, \
3043, 3042, 3040, 3039, 3038, 3036, 3035, 3033, 3032, 3031, 3029, \
3028, 3027, 3025, 3024, 3022, 3021, 3020, 3018, 3017, 3015, 3014, \
3013, 3011, 3010, 3009, 3007, 3006, 3004, 3003, 3002, 3000, 2999, \
2997, 2996, 2995, 2993, 2992, 2990, 2989, 2988, 2986, 2985, 2983, \
2982, 2981, 2979, 2978, 2976, 2975, 2974, 2972, 2971, 2969, 2968, \
2967, 2965, 2964, 2962, 2961, 2960, 2958, 2957, 2955, 2954, 2953, \
2951, 2950, 2948, 2947, 2946, 2944, 2943, 2941, 2940, 2939, 2937, \
2936, 2934, 2933, 2931, 2930, 2929, 2927, 2926, 2924, 2923, 2921, \
2920, 2919, 2917, 2916, 2914, 2913, 2912, 2910, 2909, 2907, 2906, \
2904, 2903, 2902, 2900, 2899, 2897, 2896, 2894, 2893, 2892, 2890, \
2889, 2887, 2886, 2884, 2883, 2882, 2880, 2879, 2877, 2876, 2874, \
2873, 2871, 2870, 2869, 2867, 2866, 2864, 2863, 2861, 2860, 2859, \
2857, 2856, 2854, 2853, 2851, 2850, 2848, 2847, 2846, 2844, 2843, \
2841, 2840, 2838, 2837, 2835, 2834, 2832, 2831, 2830, 2828, 2827, \
2825, 2824, 2822, 2821, 2819, 2818, 2817, 2815, 2814, 2812, 2811, \
2809, 2808, 2806, 2805, 2803, 2802, 2800, 2799, 2798, 2796, 2795, \
2793, 2792, 2790, 2789, 2787, 2786, 2784, 2783, 2781, 2780, 2779, \
2777, 2776, 2774, 2773, 2771, 2770, 2768, 2767, 2765, 2764, 2762, \
2761, 2759, 2758, 2756, 2755, 2754, 2752, 2751, 2749, 2748, 2746, \
2745, 2743, 2742, 2740, 2739, 2737, 2736, 2734, 2733, 2731, 2730, \
2728, 2727, 2725, 2724, 2722, 2721, 2720, 2718, 2717, 2715, 2714, \
2712, 2711, 2709, 2708, 2706, 2705, 2703, 2702, 2700, 2699, 2697, \
2696, 2694, 2693, 2691, 2690, 2688, 2687, 2685, 2684, 2682, 2681, \
2679, 2678, 2676, 2675, 2673, 2672, 2670, 2669, 2667, 2666, 2664, \
2663, 2661, 2660, 2658, 2657, 2655, 2654, 2652, 2651, 2649, 2648, \
2646, 2645, 2643, 2642, 2640, 2639, 2637, 2636, 2634, 2633, 2631, \
2630, 2628, 2627, 2625, 2624, 2622, 2621, 2619, 2618, 2616, 2615, \
2613, 2612, 2610, 2609, 2607, 2606, 2604, 2603, 2601, 2600, 2598, \
2597, 2595, 2594, 2592, 2591, 2589, 2588, 2586, 2585, 2583, 2581, \
2580, 2578, 2577, 2575, 2574, 2572, 2571, 2569, 2568, 2566, 2565, \
2563, 2562, 2560, 2559, 2557, 2556, 2554, 2553, 2551, 2550, 2548, \
2547, 2545, 2543, 2542, 2540, 2539, 2537, 2536, 2534, 2533, 2531, \
2530, 2528, 2527, 2525, 2524, 2522, 2521, 2519, 2518, 2516, 2514, \
2513, 2511, 2510, 2508, 2507, 2505, 2504, 2502, 2501, 2499, 2498, \
2496, 2495, 2493, 2492, 2490, 2488, 2487, 2485, 2484, 2482, 2481, \
2479, 2478, 2476, 2475, 2473, 2472, 2470, 2468, 2467, 2465, 2464, \
2462, 2461, 2459, 2458, 2456, 2455, 2453, 2452, 2450, 2448, 2447, \
2445, 2444, 2442, 2441, 2439, 2438, 2436, 2435, 2433, 2432, 2430, \
2428, 2427, 2425, 2424, 2422, 2421, 2419, 2418, 2416, 2415, 2413, \
2411, 2410, 2408, 2407, 2405, 2404, 2402, 2401, 2399, 2398, 2396, \
2394, 2393, 2391, 2390, 2388, 2387, 2385, 2384, 2382, 2381, 2379, \
2377, 2376, 2374, 2373, 2371, 2370, 2368, 2367, 2365, 2363, 2362, \
2360, 2359, 2357, 2356, 2354, 2353, 2351, 2349, 2348, 2346, 2345, \
2343, 2342, 2340, 2339, 2337, 2335, 2334, 2332, 2331, 2329, 2328, \
2326, 2325, 2323, 2321, 2320, 2318, 2317, 2315, 2314, 2312, 2311, \
2309, 2307, 2306, 2304, 2303, 2301, 2300, 2298, 2297, 2295, 2293, \
2292, 2290, 2289, 2287, 2286, 2284, 2283, 2281, 2279, 2278, 2276, \
2275, 2273, 2272, 2270, 2268, 2267, 2265, 2264, 2262, 2261, 2259, \
2258, 2256, 2254, 2253, 2251, 2250, 2248, 2247, 2245, 2244, 2242, \
2240, 2239, 2237, 2236, 2234, 2233, 2231, 2229, 2228, 2226, 2225, \
2223, 2222, 2220, 2218, 2217, 2215, 2214, 2212, 2211, 2209, 2208, \
2206, 2204, 2203, 2201, 2200, 2198, 2197, 2195, 2193, 2192, 2190, \
2189, 2187, 2186, 2184, 2182, 2181, 2179, 2178, 2176, 2175, 2173, \
2171, 2170, 2168, 2167, 2165, 2164, 2162, 2161, 2159, 2157, 2156, \
2154, 2153, 2151, 2150, 2148, 2146, 2145, 2143, 2142, 2140, 2139, \
2137, 2135, 2134, 2132, 2131, 2129, 2128, 2126, 2124, 2123, 2121, \
2120, 2118, 2117, 2115, 2113, 2112, 2110, 2109, 2107, 2106, 2104, \
2102, 2101, 2099, 2098, 2096, 2095, 2093, 2091, 2090, 2088, 2087, \
2085, 2084, 2082, 2080, 2079, 2077, 2076, 2074, 2073, 2071, 2069, \
2068, 2066, 2065, 2063, 2062, 2060, 2058, 2057, 2055, 2054, 2052, \
2051, 2049, 2048, 2046, 2044, 2043, 2041, 2040, 2038, 2037, 2035, \
2033, 2032, 2030, 2029, 2027, 2026, 2024, 2022, 2021, 2019, 2018, \
2016, 2015, 2013, 2011, 2010, 2008, 2007, 2005, 2004, 2002, 2000, \
1999, 1997, 1996, 1994, 1993, 1991, 1989, 1988, 1986, 1985, 1983, \
1982, 1980, 1978, 1977, 1975, 1974, 1972, 1971, 1969, 1967, 1966, \
1964, 1963, 1961, 1960, 1958, 1956, 1955, 1953, 1952, 1950, 1949, \
1947, 1945, 1944, 1942, 1941, 1939, 1938, 1936, 1934, 1933, 1931, \
1930, 1928, 1927, 1925, 1924, 1922, 1920, 1919, 1917, 1916, 1914, \
1913, 1911, 1909, 1908, 1906, 1905, 1903, 1902, 1900, 1898, 1897, \
1895, 1894, 1892, 1891, 1889, 1887, 1886, 1884, 1883, 1881, 1880, \
1878, 1877, 1875, 1873, 1872, 1870, 1869, 1867, 1866, 1864, 1862, \
1861, 1859, 1858, 1856, 1855, 1853, 1851, 1850, 1848, 1847, 1845, \
1844, 1842, 1841, 1839, 1837, 1836, 1834, 1833, 1831, 1830, 1828, \
1827, 1825, 1823, 1822, 1820, 1819, 1817, 1816, 1814, 1812, 1811, \
1809, 1808, 1806, 1805, 1803, 1802, 1800, 1798, 1797, 1795, 1794, \
1792, 1791, 1789, 1788, 1786, 1784, 1783, 1781, 1780, 1778, 1777, \
1775, 1774, 1772, 1770, 1769, 1767, 1766, 1764, 1763, 1761, 1760, \
1758, 1756, 1755, 1753, 1752, 1750, 1749, 1747, 1746, 1744, 1742, \
1741, 1739, 1738, 1736, 1735, 1733, 1732, 1730, 1728, 1727, 1725, \
1724, 1722, 1721, 1719, 1718, 1716, 1714, 1713, 1711, 1710, 1708, \
1707, 1705, 1704, 1702, 1701, 1699, 1697, 1696, 1694, 1693, 1691, \
1690, 1688, 1687, 1685, 1684, 1682, 1680, 1679, 1677, 1676, 1674, \
1673, 1671, 1670, 1668, 1667, 1665, 1663, 1662, 1660, 1659, 1657, \
1656, 1654, 1653, 1651, 1650, 1648, 1647, 1645, 1643, 1642, 1640, \
1639, 1637, 1636, 1634, 1633, 1631, 1630, 1628, 1627, 1625, 1623, \
1622, 1620, 1619, 1617, 1616, 1614, 1613, 1611, 1610, 1608, 1607, \
1605, 1603, 1602, 1600, 1599, 1597, 1596, 1594, 1593, 1591, 1590, \
1588, 1587, 1585, 1584, 1582, 1581, 1579, 1577, 1576, 1574, 1573, \
1571, 1570, 1568, 1567, 1565, 1564, 1562, 1561, 1559, 1558, 1556, \
1555, 1553, 1552, 1550, 1548, 1547, 1545, 1544, 1542, 1541, 1539, \
1538, 1536, 1535, 1533, 1532, 1530, 1529, 1527, 1526, 1524, 1523, \
1521, 1520, 1518, 1517, 1515, 1514, 1512, 1510, 1509, 1507, 1506, \
1504, 1503, 1501, 1500, 1498, 1497, 1495, 1494, 1492, 1491, 1489, \
1488, 1486, 1485, 1483, 1482, 1480, 1479, 1477, 1476, 1474, 1473, \
1471, 1470, 1468, 1467, 1465, 1464, 1462, 1461, 1459, 1458, 1456, \
1455, 1453, 1452, 1450, 1449, 1447, 1446, 1444, 1443, 1441, 1440, \
1438, 1437, 1435, 1434, 1432, 1431, 1429, 1428, 1426, 1425, 1423, \
1422, 1420, 1419, 1417, 1416, 1414, 1413, 1411, 1410, 1408, 1407, \
1405, 1404, 1402, 1401, 1399, 1398, 1396, 1395, 1393, 1392, 1390, \
1389, 1387, 1386, 1384, 1383, 1381, 1380, 1378, 1377, 1375, 1374, \
1373, 1371, 1370, 1368, 1367, 1365, 1364, 1362, 1361, 1359, 1358, \
1356, 1355, 1353, 1352, 1350, 1349, 1347, 1346, 1344, 1343, 1341, \
1340, 1339, 1337, 1336, 1334, 1333, 1331, 1330, 1328, 1327, 1325, \
1324, 1322, 1321, 1319, 1318, 1316, 1315, 1314, 1312, 1311, 1309, \
1308, 1306, 1305, 1303, 1302, 1300, 1299, 1297, 1296, 1295, 1293, \
1292, 1290, 1289, 1287, 1286, 1284, 1283, 1281, 1280, 1278, 1277, \
1276, 1274, 1273, 1271, 1270, 1268, 1267, 1265, 1264, 1263, 1261, \
1260, 1258, 1257, 1255, 1254, 1252, 1251, 1249, 1248, 1247, 1245, \
1244, 1242, 1241, 1239, 1238, 1236, 1235, 1234, 1232, 1231, 1229, \
1228, 1226, 1225, 1224, 1222, 1221, 1219, 1218, 1216, 1215, 1213, \
1212, 1211, 1209, 1208, 1206, 1205, 1203, 1202, 1201, 1199, 1198, \
1196, 1195, 1193, 1192, 1191, 1189, 1188, 1186, 1185, 1183, 1182, \
1181, 1179, 1178, 1176, 1175, 1174, 1172, 1171, 1169, 1168, 1166, \
1165, 1164, 1162, 1161, 1159, 1158, 1156, 1155, 1154, 1152, 1151, \
1149, 1148, 1147, 1145, 1144, 1142, 1141, 1140, 1138, 1137, 1135, \
1134, 1133, 1131, 1130, 1128, 1127, 1126, 1124, 1123, 1121, 1120, \
1119, 1117, 1116, 1114, 1113, 1112, 1110, 1109, 1107, 1106, 1105, \
1103, 1102, 1100, 1099, 1098, 1096, 1095, 1093, 1092, 1091, 1089, \
1088, 1086, 1085, 1084, 1082, 1081, 1080, 1078, 1077, 1075, 1074, \
1073, 1071, 1070, 1068, 1067, 1066, 1064, 1063, 1062, 1060, 1059, \
1057, 1056, 1055, 1053, 1052, 1051, 1049, 1048, 1046, 1045, 1044, \
1042, 1041, 1040, 1038, 1037, 1036, 1034, 1033, 1031, 1030, 1029, \
1027, 1026, 1025, 1023, 1022, 1021, 1019, 1018, 1017, 1015, 1014, \
1012, 1011, 1010, 1008, 1007, 1006, 1004, 1003, 1002, 1000, 999, 998, \
996, 995, 994, 992, 991, 989, 988, 987, 985, 984, 983, 981, 980, 979, \
977, 976, 975, 973, 972, 971, 969, 968, 967, 965, 964, 963, 961, 960, \
959, 957, 956, 955, 953, 952, 951, 949, 948, 947, 945, 944, 943, 941, \
940, 939, 938, 936, 935, 934, 932, 931, 930, 928, 927, 926, 924, 923, \
922, 920, 919, 918, 917, 915, 914, 913, 911, 910, 909, 907, 906, 905, \
903, 902, 901, 900, 898, 897, 896, 894, 893, 892, 890, 889, 888, 887, \
885, 884, 883, 881, 880, 879, 878, 876, 875, 874, 872, 871, 870, 869, \
867, 866, 865, 863, 862, 861, 860, 858, 857, 856, 854, 853, 852, 851, \
849, 848, 847, 846, 844, 843, 842, 840, 839, 838, 837, 835, 834, 833, \
832, 830, 829, 828, 827, 825, 824, 823, 822, 820, 819, 818, 816, 815, \
814, 813, 811, 810, 809, 808, 806, 805, 804, 803, 801, 800, 799, 798, \
796, 795, 794, 793, 792, 790, 789, 788, 787, 785, 784, 783, 782, 780, \
779, 778, 777, 775, 774, 773, 772, 771, 769, 768, 767, 766, 764, 763, \
762, 761, 760, 758, 757, 756, 755, 753, 752, 751, 750, 749, 747, 746, \
745, 744, 743, 741, 740, 739, 738, 736, 735, 734, 733, 732, 730, 729, \
728, 727, 726, 724, 723, 722, 721, 720, 718, 717, 716, 715, 714, 713, \
711, 710, 709, 708, 707, 705, 704, 703, 702, 701, 699, 698, 697, 696, \
695, 694, 692, 691, 690, 689, 688, 687, 685, 684, 683, 682, 681, 679, \
678, 677, 676, 675, 674, 672, 671, 670, 669, 668, 667, 666, 664, 663, \
662, 661, 660, 659, 657, 656, 655, 654, 653, 652, 651, 649, 648, 647, \
646, 645, 644, 643, 641, 640, 639, 638, 637, 636, 635, 633, 632, 631, \
630, 629, 628, 627, 625, 624, 623, 622, 621, 620, 619, 618, 616, 615, \
614, 613, 612, 611, 610, 609, 607, 606, 605, 604, 603, 602, 601, 600, \
599, 597, 596, 595, 594, 593, 592, 591, 590, 589, 588, 586, 585, 584, \
583, 582, 581, 580, 579, 578, 577, 575, 574, 573, 572, 571, 570, 569, \
568, 567, 566, 565, 564, 562, 561, 560, 559, 558, 557, 556, 555, 554, \
553, 552, 551, 550, 548, 547, 546, 545, 544, 543, 542, 541, 540, 539, \
538, 537, 536, 535, 534, 533, 531, 530, 529, 528, 527, 526, 525, 524, \
523, 522, 521, 520, 519, 518, 517, 516, 515, 514, 513, 512, 511, 509, \
508, 507, 506, 505, 504, 503, 502, 501, 500, 499, 498, 497, 496, 495, \
494, 493, 492, 491, 490, 489, 488, 487, 486, 485, 484, 483, 482, 481, \
480, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468, 467, \
466, 465, 464, 463, 462, 461, 460, 459, 458, 457, 456, 455, 454, 453, \
452, 451, 450, 449, 448, 447, 446, 445, 444, 443, 442, 441, 440, 439, \
438, 437, 436, 435, 434, 433, 432, 431, 430, 430, 429, 428, 427, 426, \
425, 424, 423, 422, 421, 420, 419, 418, 417, 416, 415, 414, 413, 412, \
411, 410, 410, 409, 408, 407, 406, 405, 404, 403, 402, 401, 400, 399, \
398, 397, 396, 395, 395, 394, 393, 392, 391, 390, 389, 388, 387, 386, \
385, 384, 384, 383, 382, 381, 380, 379, 378, 377, 376, 375, 374, 373, \
373, 372, 371, 370, 369, 368, 367, 366, 365, 365, 364, 363, 362, 361, \
360, 359, 358, 357, 356, 356, 355, 354, 353, 352, 351, 350, 349, 349, \
348, 347, 346, 345, 344, 343, 342, 342, 341, 340, 339, 338, 337, 336, \
336, 335, 334, 333, 332, 331, 330, 330, 329, 328, 327, 326, 325, 324, \
324, 323, 322, 321, 320, 319, 319, 318, 317, 316, 315, 314, 313, 313, \
312, 311, 310, 309, 308, 308, 307, 306, 305, 304, 304, 303, 302, 301, \
300, 299, 299, 298, 297, 296, 295, 295, 294, 293, 292, 291, 290, 290, \
289, 288, 287, 286, 286, 285, 284, 283, 282, 282, 281, 280, 279, 279, \
278, 277, 276, 275, 275, 274, 273, 272, 271, 271, 270, 269, 268, 268, \
267, 266, 265, 264, 264, 263, 262, 261, 261, 260, 259, 258, 258, 257, \
256, 255, 255, 254, 253, 252, 251, 251, 250, 249, 248, 248, 247, 246, \
245, 245, 244, 243, 243, 242, 241, 240, 240, 239, 238, 237, 237, 236, \
235, 234, 234, 233, 232, 232, 231, 230, 229, 229, 228, 227, 226, 226, \
225, 224, 224, 223, 222, 221, 221, 220, 219, 219, 218, 217, 217, 216, \
215, 214, 214, 213, 212, 212, 211, 210, 210, 209, 208, 207, 207, 206, \
205, 205, 204, 203, 203, 202, 201, 201, 200, 199, 199, 198, 197, 197, \
196, 195, 195, 194, 193, 193, 192, 191, 191, 190, 189, 189, 188, 187, \
187, 186, 185, 185, 184, 183, 183, 182, 181, 181, 180, 179, 179, 178, \
178, 177, 176, 176, 175, 174, 174, 173, 172, 172, 171, 171, 170, 169, \
169, 168, 167, 167, 166, 166, 165, 164, 164, 163, 163, 162, 161, 161, \
160, 159, 159, 158, 158, 157, 156, 156, 155, 155, 154, 153, 153, 152, \
152, 151, 150, 150, 149, 149, 148, 148, 147, 146, 146, 145, 145, 144, \
143, 143, 142, 142, 141, 141, 140, 139, 139, 138, 138, 137, 137, 136, \
136, 135, 134, 134, 133, 133, 132, 132, 131, 130, 130, 129, 129, 128, \
128, 127, 127, 126, 126, 125, 124, 124, 123, 123, 122, 122, 121, 121, \
120, 120, 119, 119, 118, 118, 117, 117, 116, 115, 115, 114, 114, 113, \
113, 112, 112, 111, 111, 110, 110, 109, 109, 108, 108, 107, 107, 106, \
106, 105, 105, 104, 104, 103, 103, 102, 102, 101, 101, 100, 100, 99, \
99, 98, 98, 98, 97, 97, 96, 96, 95, 95, 94, 94, 93, 93, 92, 92, 91, \
91, 90, 90, 90, 89, 89, 88, 88, 87, 87, 86, 86, 85, 85, 85, 84, 84, \
83, 83, 82, 82, 81, 81, 81, 80, 80, 79, 79, 78, 78, 78, 77, 77, 76, \
76, 75, 75, 75, 74, 74, 73, 73, 73, 72, 72, 71, 71, 70, 70, 70, 69, \
69, 68, 68, 68, 67, 67, 66, 66, 66, 65, 65, 64, 64, 64, 63, 63, 63, \
62, 62, 61, 61, 61, 60, 60, 59, 59, 59, 58, 58, 58, 57, 57, 56, 56, \
56, 55, 55, 55, 54, 54, 54, 53, 53, 53, 52, 52, 51, 51, 51, 50, 50, \
50, 49, 49, 49, 48, 48, 48, 47, 47, 47, 46, 46, 46, 45, 45, 45, 44, \
44, 44, 43, 43, 43, 42, 42, 42, 42, 41, 41, 41, 40, 40, 40, 39, 39, \
39, 38, 38, 38, 38, 37, 37, 37, 36, 36, 36, 35, 35, 35, 35, 34, 34, \
34, 33, 33, 33, 33, 32, 32, 32, 32, 31, 31, 31, 30, 30, 30, 30, 29, \
29, 29, 29, 28, 28, 28, 28, 27, 27, 27, 27, 26, 26, 26, 26, 25, 25, \
25, 25, 24, 24, 24, 24, 23, 23, 23, 23, 22, 22, 22, 22, 21, 21, 21, \
21, 21, 20, 20, 20, 20, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 17, \
17, 17, 17, 17, 16, 16, 16, 16, 16, 15, 15, 15, 15, 15, 14, 14, 14, \
14, 14, 14, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 11, 11, 11, \
11, 11, 11, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8, \
8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, \
5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, \
3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, \
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, \
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

uint16_t cos4096(uint32_t in_t)
{
	uint16_t valid16 = in_t % PERIOD_SIZE;
	bool flip = false;
	if(valid16 >=  TABLE_SIZE) {
		flip = true;
	}
	if(!flip) return costable[valid16];
	return TABLE_MAX_VALUE-costable[valid16-TABLE_SIZE];
}
