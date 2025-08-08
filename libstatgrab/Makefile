# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/994 (as deps)

include $(TOPDIR)/rules.mk

PKG_NAME:=libstatgrab
PKG_VERSION:=0.92.1
PKG_RELEASE:=1

PKG_TAG:=$(call toupper,$(PKG_NAME))_$(subst .,_,$(PKG_VERSION))

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/libstatgrab/libstatgrab/tar.gz/refs/tags/$(PKG_TAG)?
PKG_HASH:=fb75ba97e6e71f220baf015790e6deb21c77e29e4fbdb3f5de133d7f4564edc8

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.1-or-later LGPL-2.1-or-later
PKG_LICENSE_FILES:=COPYING COPYING.LGPL

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

PKG_UNPACK += --strip-components=1 -C $(PKG_BUILD_DIR)

define Package/libstatgrab
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Provides a useful interface to system statistics
  URL:=https://libstatgrab.org
endef

define Package/libstatgrab/description
  A cross platform library for accessing system statistics.
endef

define Package/saidar
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=a curses-based tool for viewing system statistics
  URL:=https://libstatgrab.org
  DEPENDS:=+libncursesw +libstatgrab
endef

define Package/saidar/description
  saidar is a curses-based tool for viewing the
  system statistics available through libstatgrab. Statistics include
  CPU, processes, load, memory, swap, network I/O, disk I/O, and file
  system information.
endef

define Package/statgrab
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=sysctl-style interface to system statistics
  URL:=https://libstatgrab.org
  DEPENDS:=+libstatgrab +perlbase-getopt
endef

define Package/statgrab/description
  statgrab provides a sysctl-style interface to all
  the system statistics available through libstatgrab. This is useful
  for applications that don't want to make library calls, but still
  want to access the statistics.
endef

CONFIGURE_ARGS += \
	--disable-man

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/statgrab.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libstatgrab.{a,so*} $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libstatgrab.pc \
		$(1)/opt/lib/pkgconfig
endef

define Package/libstatgrab/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libstatgrab.so* $(1)/opt/lib
endef

define Package/saidar/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/saidar $(1)/opt/bin
endef

define Package/statgrab/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/statgrab* $(1)/opt/bin
	$(SED) 's,^#!.*perl,#!/opt/bin/perl,' $(1)/opt/bin/statgrab-make-mrtg-*
endef

$(eval $(call BuildPackage,libstatgrab))
$(eval $(call BuildPackage,saidar))
$(eval $(call BuildPackage,statgrab))
