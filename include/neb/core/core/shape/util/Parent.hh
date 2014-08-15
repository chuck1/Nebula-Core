#ifndef __GLUTPP_PARENT_H__
#define __GLUTPP_PARENT_H__

#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gal/std/shared.hpp>

#include <neb/core/interface/Pose.hh>
#include <neb/core/core/actor/util/Types.hh>
#include <neb/core/core/actor/util/Cast.hh>
#include <neb/core/core/shape/util/Cast.hh>
#include <neb/core/util/parent.hpp>

namespace neb { namespace core { namespace shape { namespace util {
			/** @brief @Parent
			 * abstract class for parent of a shape
			 *
			 * @note inheritance of neb::util::parent is non-virtual
			 */
			class parent:
				virtual public neb::util::parent<neb::core::shape::base>,
				virtual public neb::core::actor::util::cast,
				virtual public neb::core::shape::util::cast,
				virtual public neb::core::Pose
			{
				public:
					virtual ~parent() {}
			};
}}}}


#endif






