#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libebml
PKG_VERSION:=1.3.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://dl.matroska.org/downloads/libebml
PKG_HASH:=c6b6c6cd8b20a46203cb5dce636883aef68beb2846f1e4103b660a7da2c9c548

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/libebml
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libstdcpp
	TITLE:=Extensible Binary Meta Language access library
	URL:=http://matroska.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libebml/description
 libEBML - Extensible Binary Meta Language access library.
endef

CMAKE_OPTIONS += -DBUILD_SHARED_LIBS=YES

define Package/libebml/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libebml.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libebml))
