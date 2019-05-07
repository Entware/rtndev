#
# Copyright (C) 2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2013

include $(TOPDIR)/rules.mk

PKG_NAME:=extundelete
PKG_VERSION:=0.2.4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/extundelete/$(PKG_VERSION)
PKG_HASH:=a1f9dd61247056d36401ce5d6785e74d08a184340eebd3865c345ddaa93f19f4

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/extundelete
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libext2fs +libstdcpp
	TITLE:=ext3/4 undelete utility
	URL:=http://extundelete.sourceforge.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/extundelete/description
 Extundelete is a utility to undelete files from an ext3 or ext4 partition.
endef

TARGET_LDFLAGS += \
	-lpthread -luuid -lblkid -lss -lcom_err -ldl

define Package/extundelete/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/extundelete $(1)/opt/bin
endef

$(eval $(call BuildPackage,extundelete))
