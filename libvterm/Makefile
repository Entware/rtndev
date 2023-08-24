#
# Copyright (C) 2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# only build static library (neovim)

include $(TOPDIR)/rules.mk

PKG_NAME:=libvterm
PKG_VERSION:=0.3.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.leonerd.org.uk/code/libvterm
PKG_HASH:=91eb5088069f4e6edab69e14c4212f6da0192e65695956dc048016a0dab8bcf6

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=LICENSE

include $(INCLUDE_DIR)/package.mk

define Package/libvterm
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=a VT220/xterm/ECMA-48 terminal emulator library
  URL:=https://www.leonerd.org.uk/code/libvterm
  PKG_MAINTAINER:=Entware team, https://entware.net
  BUILDONLY:=1
endef

define Package/libvterm/description
  An abstract C99 library which implements
  a VT220 or xterm-like terminal emulator.
endef

Build/Configure:=:

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_BUILD_DIR)/include/*.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_BUILD_DIR)/.libs/libvterm.a $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_BUILD_DIR)/vterm.pc.in $(1)/opt/lib/pkgconfig/vterm.pc
endef

$(eval $(call BuildPackage,libvterm))
