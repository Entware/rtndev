#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# based on Makefile from https://github.com/MarvAmBass/lede-gnupg2.git

include $(TOPDIR)/rules.mk

PKG_NAME:=npth
PKG_VERSION:=1.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://www.gnupg.org/ftp/gcrypt/npth/
PKG_HASH:=1393abd9adcf0762d34798dc34fdcf4d0d22a8410721e76f1e3afcd1daa4e2d1

PKG_LICENSE:=GPL-2.1
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/npth
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libgpg-error
  TITLE:=npth The New GNU Portable Threads Library.
  URL:=http://www.gnupg.org/
endef


define Package/npth/description
 nPth is a library to provide the GNU Pth API and thus a non-preemptive threads implementation.

 In contrast to GNU Pth is is based on the system's standard threads implementation. This allows the use of libraries which are not compatible to GNU Pth. Experience with a Windows Pth emulation showed that this is a solid way to provide a co-routine based framework.
endef

TARGET_CFLAGS += $(FPIC)

CONFIGURE_ARGS += --enable-shared --enable-static

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/bin $(2)/bin $(1)/opt/include $(1)/opt/lib $(1)/opt/share/aclocal
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/npth-config $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/include/npth*.h $(1)/opt/include/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libnpth.{la,a,so*} $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/share/aclocal/npth.m4 $(1)/opt/share/aclocal/
	$(SED) 's,^\(prefix\|exec_prefix\)=.*,\1=$(STAGING_DIR)/opt,g' $(1)/opt/bin/npth-config
	ln -sf $(STAGING_DIR)/opt/bin/npth-config $(2)/bin/
endef

define Package/npth/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libnpth.so.* $(1)/opt/lib/
endef

$(eval $(call BuildPackage,npth))
