#
# Copyright (C) 2020-2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=wcd
PKG_VERSION:=6.0.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/wcd/$(PKG_VERSION)
PKG_HASH:=f2970e01a52886d330604490fdbedd7373faff0910ff2e14889435677f563763

include $(INCLUDE_DIR)/package.mk

define Package/wcd
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libncursesw +libunistring
	TITLE:=chdir for DOS and Unix
	URL:=https://waterlan.home.xs4all.nl
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/wcd/description
 WCD (Wherever Change Directory) is a command-line program to change directory
 fast. It saves time typing at the keyboard. One needs to type only a part of
 a directory name and wcd will jump to it. Wcd has a fast selection method
 in case of multiple matches and allows aliasing and banning of directories.
 Wcd also includes a full screen interactive directory tree browser with speed
 search.
endef

MAKE_FLAGS += \
	EXT= \
	ENABLE_NLS= \
	DOTWCD=1 \
	UNINORM=1 \
	INCPREFIX="$(STAGING_DIR)/opt" \
	prefix=/opt

define Package/wcd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/wcd $(1)/opt/bin
endef

$(eval $(call BuildPackage,wcd))
