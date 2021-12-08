#
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cmake
PKG_VERSION:=3.22.1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://cmake.org/files/v$(PKG_VERSION) \
		https://fossies.org/linux/misc
PKG_HASH:=0e998229549d7b3f368703d20e248e7ee1f853910d42704aa87918c213ea82c0

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
