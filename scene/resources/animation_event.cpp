/**************************************************************************/
/*  animation_event.cpp                                                   */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "animation_event.h"
#include "core/object/object.h"
#include "core/string/string_name.h"

void AnimationEvent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_event_name", "event_name"), &AnimationEvent::set_event_name);
	ClassDB::bind_method(D_METHOD("get_event_name"), &AnimationEvent::get_event_name);

	ClassDB::bind_method(D_METHOD("set_tag_color", "tag_color"), &AnimationEvent::set_tag_color);
	ClassDB::bind_method(D_METHOD("get_tag_color"), &AnimationEvent::get_tag_color);

	ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "event_name", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT), "set_event_name", "get_event_name");
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "tag_color", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_DEFAULT), "set_tag_color", "get_tag_color");
}

void AnimationEvent::set_event_name(const StringName &p_event_name) {
	event_name = p_event_name;
	emit_changed();
}
StringName AnimationEvent::get_event_name() const {
	return event_name;
}

void AnimationEvent::set_tag_color(const Color &p_color) {
	tag_color = p_color;
	emit_changed();
}
Color AnimationEvent::get_tag_color() const {
	return tag_color;
}

AnimationEvent::AnimationEvent() {
	event_name = StringName();
	tag_color = Color(1, 1, 1);
}