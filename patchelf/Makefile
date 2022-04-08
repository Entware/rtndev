#
# Copyright (C) 2018-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=patchelf
PKG_VERSION:=0.14.5
PKG_REV:=a35054504293f9ff64539850d1ed0bfd2f5399f2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/NixOS/patchelf.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=06a8c6b6148a869d88de679d76c4b6fa642088a9b154caad12e5a79f947d82af

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
