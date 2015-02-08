
#include <neb/core/math/pose.hpp>

neb::fnd::math::pose::pose():
	pos_(0.0,0.0,0.0)
{};
neb::fnd::math::pose::pose(neb::fnd::math::pose const & rhs):
	pos_(rhs.pos_),
	rot_(rhs.rot_)
{}
neb::fnd::math::pose::pose(neb::fnd::math::pose&& rhs):
	pos_(::std::move(rhs.pos_)),
	rot_(::std::move(rhs.rot_))
{}
neb::fnd::math::pose::pose(glm::vec3 p):
	pos_(p)
{}
neb::fnd::math::pose::pose(glm::quat q):
	pos_(0.0,0.0,0.0),
	rot_(q)
{}
neb::fnd::math::pose::pose(glm::vec3 p, glm::quat q):
	pos_(p),
	rot_(q)
{}
neb::fnd::math::pose&		neb::fnd::math::pose::operator=(neb::fnd::math::pose const & rhs) {
	pos_ = rhs.pos_;
	rot_ = rhs.rot_;
	return *this;
}
neb::fnd::math::pose		neb::fnd::math::pose::operator*(neb::fnd::math::pose const & rhs) const {
	pose ret;
	ret.pos_ = pos_ + rot_ * rhs.pos_;
	ret.rot_ = rot_ * rhs.rot_;
	return ret;
}

glm::mat4		neb::fnd::math::pose::mat4_cast() const {
	//mat4 ret(glm::mat4_cast(rot_));
	//return glm::translate(ret, vec3(pos_));

	glm::mat4 ret = glm::translate(glm::mat4(), glm::vec3(pos_)) * glm::mat4_cast(rot_);

	return ret;

}

