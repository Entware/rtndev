#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=encfs
PKG_VERSION:=1.9.5
PKG_REV:=7fc3730f67888106ade57a66d3da10a9f825d199
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/vgough/encfs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk
include $(INCLUDE_DIR)/nls.mk

define Package/encfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libopenssl +libstdcpp +fuse-utils +libatomic $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=encrypted filesystem in user-space
	URL:=http://www.arg0.net/#!encfs/c1awt
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/encfs/description
 EncFS provides an encrypted filesystem in user-space. It runs without any
 special permissions and uses the FUSE library module to provide the filesystem
 interface.
endef

CMAKE_OPTIONS += \
	-DBUILD_UNIT_TESTS=OFF

TARGET_LDFLAGS += -lpthread -latomic -lintl

define Package/encfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/encfs.bin $(1)/opt/bin/encfs
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/encfs{sh,ctl} $(1)/opt/bin
endef

$(eval $(call BuildPackage,encfs))
