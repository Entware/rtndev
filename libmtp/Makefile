# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware
#
# The newer version requires host compilation with their own deps

include $(TOPDIR)/rules.mk

PKG_NAME:=libmtp
PKG_VERSION:=1.1.21
PKG_REV:=3b417127bf92c660053dea7d106021dc805d0f73
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/libmtp/libmtp.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=15818aca20921e2d893365dd4fb7c2ff2e052c33e57b426a0f1da1d79576b92e

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/libmtp/Default
	SUBMENU:=Filesystem
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libmtp
	$(call Package/libmtp/Default)
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libgcrypt +libusb-1.0 $(ICONV_DEPENDS)
	TITLE:=a library to access MTP devices
endef

define Package/libmtp-utils
	$(call Package/libmtp/Default)
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libmtp
	TITLE:=libmtp utilities
endef

define Package/libmtp/description
 libmtp implements an MTP initiator, which means it initiate
 MTP sessions with devices. The devices responding are known
 as MTP responders. libmtp runs on something with a USB host
 controller interface, using libusb to access the host controller.
endef

define Package/libmtp-utils/description
 nfs-ls, nfs-cat, nfs-cp console usersapce utilities for accessing NFS shares
 over a network.
endef

CONFIGURE_ARGS += \
	--with-libiconv-prefix=$(ICONV_PREFIX) \
	--with-udev=/opt/lib/udev \
	--disable-configfiles

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/* $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmtp.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libmtp.pc $(1)/opt/lib/pkgconfig
endef

define Package/libmtp/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmtp.so* $(1)/opt/lib
endef

define Package/libmtp-utils/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mtp-* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib/udev
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/udev/mtp-probe $(1)/opt/lib/udev
endef

$(eval $(call BuildPackage,libmtp))
$(eval $(call BuildPackage,libmtp-utils))
