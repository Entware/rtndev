# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2017-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=cmake
PKG_VERSION:=4.0.2
PKG_VERSION_MAJOR:=$(subst $(space),.,$(wordlist 1,2,$(subst .,$(space),$(PKG_VERSION))))
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/Kitware/CMake/releases/download/v$(PKG_VERSION)/ \
		https://cmake.org/files/v$(PKG_VERSION_MAJOR)/
PKG_HASH:=1c3a82c8ca7cf12e0b17178f9d0c32f7ac773bd5651a98fcfd80fbf4977f8d48

PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=Copyright.txt

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cmake
	SECTION:=devel
	CATEGORY:=Development
	TITLE:=CMake tools
	URL:=https://cmake.org
	DEPENDS:=+jsoncpp +libcurl +libexpat +libncursesw +libstdcpp +libuv +zlib
	EXTRA_DEPENDS:=zlib-dev
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cmake/description
 CMake is an open-source, cross-platform family of tools designed to build,
 test and package software.
endef

TARGET_LDFLAGS += -pthread

CMAKE_OPTIONS += \
	-DBUILD_CursesDialog=1 \
	-DCMAKE_USE_SYSTEM_CURL=ON \
	-DCMAKE_USE_SYSTEM_EXPAT=ON \
	-DCMAKE_USE_SYSTEM_FORM=ON \
	-DCMAKE_USE_SYSTEM_JSONCPP=ON \
	-DCMAKE_USE_SYSTEM_LIBARCHIVE=OFF \
	-DCMAKE_USE_SYSTEM_LIBUV=ON \
	-DCMAKE_USE_SYSTEM_NGHTTP2=ON \
	-DCMAKE_USE_SYSTEM_ZLIB=ON

define Package/cmake/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/{bin,share} $(1)/opt
endef

$(eval $(call BuildPackage,cmake))
