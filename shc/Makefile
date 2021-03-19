#
# Copyright (C) 2017 Joakim Plate <joakim.plate@gmail.com>
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=shc
PKG_VERSION:=4.0.3
PKG_REV:=7e5b6be461fb29a2e9ada116b00eadcc4d5b9b1b
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/neurobin/shc.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/shc
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Shells
	DEPENDS:=+gcc
	TITLE:=A generic shell script compiler
	URL:=https://neurobin.org/projects/softwares/unix/shc/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/shc/description
 Shc takes a script, which is specified on the command line and produces C
 source code. The generated source code is then compiled and linked to produce
 a stripped binary executable.
endef

define Package/shc/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/shc $(1)/opt/bin
endef

$(eval $(call BuildPackage,shc))
