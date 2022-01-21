#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "rtweekend.h"

//material and hittable gets to know each other so we can store what material gets hit and know how to react
class material;

struct hit_record {
    point3 p;
    vec3 normal;
    shared_ptr<material> mat_ptr;
    double t;

    //check to see if the ray hits inside or outside aka front face
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};
//this is something a ray can intersect with
class hittable {
    public:
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record&rec) const = 0;
};

#endif