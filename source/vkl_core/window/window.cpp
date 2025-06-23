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

#include "window.h"

namespace vkl
{
    Window::Window(const char* name, int width, int height) :_name(name), _width(width), _height(height)
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        _window = glfwCreateWindow(_width, _height, _name, nullptr, nullptr);
        glfwSetWindowUserPointer(_window, this);
    }

    Window::~Window()
    {
        glfwDestroyWindow(_window);
        glfwTerminate();
        _window = nullptr;
    }

    bool Window::should_close()
    {
        return glfwWindowShouldClose(_window);
    }

    void Window::poll_event()
    {
        glfwPollEvents();
    }
    
} // namespace vkl
