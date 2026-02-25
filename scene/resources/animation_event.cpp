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
#include "core/string/ustring.h"
#include "core/variant/dictionary.h"

void AnimationEvent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_event_name", "event_name"), &AnimationEvent::set_event_name);
	ClassDB::bind_method(D_METHOD("get_event_name"), &AnimationEvent::get_event_name);

	ClassDB::bind_method(D_METHOD("set_tag_color", "tag_color"), &AnimationEvent::set_tag_color);
	ClassDB::bind_method(D_METHOD("get_tag_color"), &AnimationEvent::get_tag_color);

	ClassDB::bind_method(D_METHOD("set_duration", "duration"), &AnimationEvent::set_duration);
	ClassDB::bind_method(D_METHOD("get_duration"), &AnimationEvent::get_duration);

	ClassDB::bind_method(D_METHOD("_set_data", "data"), &AnimationEvent::_set_data);
	ClassDB::bind_method(D_METHOD("_get_data"), &AnimationEvent::_get_data);

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "event_name", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_event_name", "get_event_name");
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "tag_color", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_tag_color", "get_tag_color");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "duration", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_EDITOR), "set_duration", "get_duration");
	ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "_data", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NO_EDITOR | PROPERTY_USAGE_INTERNAL), "_set_data", "_get_data");

	GDVIRTUAL_BIND(_get_default_event_name);
	GDVIRTUAL_BIND(_get_default_tag_color);
	GDVIRTUAL_BIND(_get_default_duration);
}

void AnimationEvent::set_event_name(const String &p_event_name) {
	_data.set("event_name", p_event_name);
	emit_changed();
}
String AnimationEvent::get_event_name() {
	if (!_data.has("event_name")) {
		if (GDVIRTUAL_IS_OVERRIDDEN(_get_default_event_name)) {
			String ret;
			GDVIRTUAL_CALL(_get_default_event_name, ret);
			set_event_name(ret);
		}
	}
	return _data.get("event_name", "");
}

void AnimationEvent::set_tag_color(const Color &p_color) {
	_data.set("tag_color", p_color);
	emit_changed();
}
Color AnimationEvent::get_tag_color() {
	if (!_data.has("tag_color")) {
		if (GDVIRTUAL_IS_OVERRIDDEN(_get_default_tag_color)) {
			Color ret;
			GDVIRTUAL_CALL(_get_default_tag_color, ret);
			set_tag_color(ret);
		}
	}
	return _data.get("tag_color", Color(1, 1, 1, 1));
}

void AnimationEvent::set_duration(const double p_duration) {
	_data.set("duration", p_duration);
	emit_changed();
}
double AnimationEvent::get_duration() {
	if (!_data.has("duration")) {
		if (GDVIRTUAL_IS_OVERRIDDEN(_get_default_duration)) {
			double ret;
			GDVIRTUAL_CALL(_get_default_duration, ret);
			set_duration(ret);
		}
	}
	return _data.get("duration", 0.0);
}

void AnimationEvent::_set_data(const Dictionary &p_data) {
	_data = p_data;
	emit_changed();
}

Dictionary AnimationEvent::_get_data() const {
	return _data;
}

AnimationEvent::AnimationEvent() {
}