# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2023-2025 Entware
#
# only build static library (neovim)
#

include $(TOPDIR)/rules.mk

PKG_NAME:=unibilium
PKG_VERSION:=2.1.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/neovim/unibilium/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=370ecb07fbbc20d91d1b350c55f1c806b06bf86797e164081ccc977fc9b3af7a

PKG_LICENSE:=GPL-3.0-or-later LGPL-3.0-or-later
PKG_LICENSE_FILES:=GPLv3 LGPLv3 LICENSE

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/unibilium
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=a terminfo parsing library
  URL:=https://github.com/mauke/unibilium
  PKG_MAINTAINER:=Entware team, https://entware.net
  BUILDONLY:=1
endef

define Package/unibilium/description
  Unibilium is a very basic terminfo library.
  It can read and write ncurses-style terminfo files,
  and it can interpret terminfo format strings.
  (forked from https://github.com/mauke/unibilium)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/unibilium.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libunibilium.a $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_BUILD_DIR)/unibilium.pc.in $(1)/opt/lib/pkgconfig/unibilium.pc
	$(SED) 's,^Version:.*,Version: $(PKG_VERSION),' $(1)/opt/lib/pkgconfig/*.pc
endef

$(eval $(call BuildPackage,unibilium))
