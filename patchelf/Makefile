#
# Copyright (C) 2018-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=patchelf
PKG_VERSION:=0.10
PKG_REV:=e1e39f3639e39360ceebb2f7ed533cede4623070
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/NixOS/patchelf.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

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
 A small utility to modify the dynamic linker and RPATH of ELF executables.
endef

define Package/patchelf/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/patchelf $(1)/opt/bin
endef

$(eval $(call BuildPackage,patchelf))
