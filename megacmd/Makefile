#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Should be linked against proper version of meganz-sdk

include $(TOPDIR)/rules.mk

PKG_NAME:=megacmd
PKG_VERSION:=1.5.0b
PKG_REV:=b984a4f69fcd9b49869eebd091ab053c1c5e5106
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/meganz/MEGAcmd.git
PKG_SOURCE_PROTO:=git
PKG_MIRROR_HASH:=6d5aaf71a75e1f9184a9d391384b97f6f8960f3493f0150ab74576670b1eb9ea

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/megacmd
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libmega +libpcre +libatomic
	TITLE:=Command Line Interactive and Scriptable Application
	URL:=https://github.com/meganz/megacmd
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/megacmd/description
 MEGAcmd provides non UI access to MEGA services. It intends to offer all the
 functionality with your MEGA account via commands.
endef

TARGET_CFLAGS += -I/$(STAGING_DIR)/opt/include/mega/posix
TARGET_CXXFLAGS += -pthread
TARGET_LDFLAGS += -lmega -latomic

define Package/megacmd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mega-* $(1)/opt/bin
	$(SED) 's,^#!.*bash,#!/opt/bin/sh,' $(1)/opt/bin/*
endef

$(eval $(call BuildPackage,megacmd))
