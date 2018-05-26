# 
# Copyright (C) 2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=patchelf
PKG_VERSION:=0.9
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/NixOS/patchelf.git
PKG_SOURCE_DATE:=2017-03-08
PKG_SOURCE_VERSION:=c4deb5e9e1ce9c98a48e0d5bb37d87739b8cfee4
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION)-$(PKG_SOURCE_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/patchelf
  SECTION:=devel
  CATEGORY:=Development
  TITLE:=patchelf
  URL:=https://nixos.org/patchelf.html
  MAINTAINER:=Entware team, https://entware.net
  DEPENDS:=+libstdcpp
endef

define Package/patchelf/description
 A small utility to modify the dynamic linker and RPATH of ELF executables
endef

define Package/patchelf/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/patchelf $(1)/opt/bin
endef

$(eval $(call BuildPackage,patchelf))
