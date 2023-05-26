# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2023 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=airprint
PKG_VERSION:=0.0.1
PKG_RELEASE:=1

MAINTAINER:=Entware team, https://entware.net

include $(INCLUDE_DIR)/package.mk

define Package/airprint
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Printing
  DEPENDS:=+avahi-dbus-daemon +cups-filters +cups-pdf +libnss-mdns +python3-cups
  TITLE:=provides print server (dummy)
  PKGARCH:=all
endef

define Package/airprint/description
 airprint is a metapackage for installing a print server for printing over Wi-Fi.
endef

Build/Prepare:=:
Build/Configure:=:
Build/Compile:=:

define Package/airprint/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) ./files/airprint-generate.py $(1)/opt/sbin

	$(INSTALL_DIR) $(1)/opt/share/cups/mime
	$(CP) files/airprint.convs $(1)/opt/share/cups/mime
	$(CP) files/airprint.types $(1)/opt/share/cups/mime
endef

define Package/airprint/postinst
#!/bin/sh

if ! grep -q '^lp:' /opt/etc/group; then
  echo "lp:x:7:" >> /opt/etc/group
fi

if ! grep -q '^lpadmin:' /opt/etc/group; then
  echo "lpadmin:x:115:" >> /opt/etc/group
fi

if ! grep -q '^nogroup:' /opt/etc/group; then
  echo "nogroup:x:65535:" >> /opt/etc/group
fi

if ! grep -q '^sys:' /opt/etc/group; then
  echo "sys:x:3:" >> /opt/etc/group
fi
endef

$(eval $(call BuildPackage,airprint))
