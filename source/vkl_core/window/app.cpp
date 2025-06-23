/*
 * VulkanLearning is a humble introduction to Vulkan graphics
 * programming. The source code for this program is available
 * at: https://github.com/BKHao/VulkanLearning
 * 
 * Copyright (C) 2025 BKHao zhao828829@qq.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "app.h"

namespace vkl
{
	App::App(const char* name, int width, int height) :_name(name), _width(width), _height(height)
	{
		_window = std::make_unique<Window>(_name, _width, _height);
	}

	App::~App()
	{

	}

	int App::run()
	{
		loop();
		return 0;
	}

	void App::loop()
	{
		while (!_window->should_close())
		{
			_window->poll_event();
		}
	}

} // namespace vkl

