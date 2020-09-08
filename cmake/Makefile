#
# Copyright (C) 2017-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cmake
PKG_VERSION:=3.18.2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://cmake.org/files/v3.18 \
		https://fossies.org/linux/misc
PKG_HASH:=5d4e40fc775d3d828c72e5c45906b4d9b59003c9433ff1b36a1cb552bbd51d7e

PKG_LICENSE:=BSD-3-Clause

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cmake
	SECTION:=devel
	CATEGORY:=Development
	TITLE:=CMake tools
	URL:=https://cmake.org
	DEPENDS:=+libcurl +libpthread +librt +libstdcpp +zlib +zlib-dev +libncursesw
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cmake/description
 CMake is an open-source, cross-platform family of tools designed to build,
 test and package software.
endef

CMAKE_OPTIONS += \
	-DCMAKE_USE_SYSTEM_CURL=ON \
	-DZLIB_INCLUDE_DIR=$(STAGING_DIR)/opt/include \
	-DZLIB_LIBRARY=$(STAGING_DIR)/opt/lib/libz.so \
	-DCURL_INCLUDE_DIR=$(STAGING_DIR)/opt/include \
	-DCURL_LIBRARY=$(STAGING_DIR)/opt/lib/libcurl.so \
	-DKWSYS_LFS_WORKS=1 \
	-DCMake_TEST_Qt5=FALSE

define Package/cmake/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/{bin,share} $(1)/opt
endef

$(eval $(call BuildPackage,cmake))
