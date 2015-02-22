#ifndef NEB_FND_DEBUG_BUFFER_HPP
#define NEB_FND_DEBUG_BUFFER_HPP

namespace neb { namespace fnd {
	class DebugLine
	{
	public:
		glm::vec3	pos0;
		unsigned int	color0;
		glm::vec3	pos1;
		unsigned int	color1;
	};
	class DebugTriangle
	{
	public:
		glm::vec3	pos0;
		unsigned int	color0;
		glm::vec3	pos1;
		unsigned int	color1;
		glm::vec3	pos2;
		unsigned int	color2;
	};
	class DebugBuffer
	{
	public:
		neb::fnd::DebugLine*		lines;
		unsigned int			nblines;
		neb::fnd::DebugTriangle*	triangles;
		unsigned int			nbtriangles;
	};
}}

#endif
