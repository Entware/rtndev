#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=shake
PKG_VERSION:=1.0-20170702
PKG_REV:=33dd09dfd77dba8e73da194d2ea4c1e0d9c90ace
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/unbrice/shake.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/shake
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libattr
	TITLE:=defragmentation utility
	URL:=http://vleu.net/shake/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/shake/description
 Shake is a defragmenter that runs in userspace.
endef

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include

define Package/shake/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{shake,unattr} $(1)/opt/bin
endef

$(eval $(call BuildPackage,shake))
