//#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "resource_utils.h"

#include "utils/error_handler.h"

#include <stb_image_write.h>

//std::string view_command(const std::filesystem::path& path)
//{
//#ifdef __APPLE__
//	return std::string("open ").append(path.string());
//#endif
//#ifdef __WINDOWS__
//	return std::string("open ").append(path.string());
//#endif
//	return path.string();
//}

using namespace cg::utils;

void cg::utils::save_resource(cg::resource<cg::unsigned_color>& render_target, const std::filesystem::path filepath)
{
	int width = static_cast<int>(render_target.get_stride());
	int height = static_cast<int>(render_target.get_number_of_elements()) / width;

	int result = stbi_write_png(
			filepath.string().c_str(), width, height, 3, render_target.get_data(),
			width * sizeof(cg::unsigned_color));

	if (result != 1)
		THROW_ERROR("Can't save the resource");

	std::string view_command("open ");
	view_command.append(filepath.string());

	std::system(view_command.c_str());
//	std::system(view_command(filepath).c_str());
}

